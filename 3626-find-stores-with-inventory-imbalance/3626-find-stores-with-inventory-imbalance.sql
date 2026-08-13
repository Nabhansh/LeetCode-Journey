WITH ranked_inventory AS (
    SELECT
        store_id,
        product_name,
        quantity,
        ROW_NUMBER() OVER (
            PARTITION BY store_id
            ORDER BY price DESC, quantity DESC, product_name ASC
        ) AS expensive_rank,
        ROW_NUMBER() OVER (
            PARTITION BY store_id
            ORDER BY price ASC, quantity DESC, product_name ASC
        ) AS cheapest_rank,
        COUNT(*) OVER (
            PARTITION BY store_id
        ) AS product_count
    FROM inventory
),
most_expensive AS (
    SELECT
        store_id,
        product_name,
        quantity
    FROM ranked_inventory
    WHERE expensive_rank = 1
      AND product_count >= 3
),
cheapest AS (
    SELECT
        store_id,
        product_name,
        quantity
    FROM ranked_inventory
    WHERE cheapest_rank = 1
)
SELECT
    s.store_id,
    s.store_name,
    s.location,
    e.product_name AS most_exp_product,
    c.product_name AS cheapest_product,
    ROUND(c.quantity / e.quantity, 2) AS imbalance_ratio
FROM stores AS s
JOIN most_expensive AS e
    ON s.store_id = e.store_id
JOIN cheapest AS c
    ON s.store_id = c.store_id
WHERE e.quantity < c.quantity
ORDER BY
    imbalance_ratio DESC,
    s.store_name ASC;