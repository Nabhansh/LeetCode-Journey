# Write your MySQL query statement below
select customer_id,count(*) as total_orders,

round((100.0*sum(case when TIME(order_timestamp) BETWEEN '11:00:00' AND '14:00:00'
OR
TIME(order_timestamp) BETWEEN '18:00:00' AND '21:00:00'
then 1
else 0 end)/count(*))) as peak_hour_percentage,
round(avg(order_rating),2) as average_rating
from restaurant_orders 
group by customer_id
having count(*)>2
and round(avg(order_rating),2)>=4.0
and 
round((100.0*sum(case when TIME(order_timestamp) BETWEEN '11:00:00' AND '14:00:00'
OR
TIME(order_timestamp) BETWEEN '18:00:00' AND '21:00:00'
then 1
else 0 end)/count(*)))>=60.00
and round(100.0*sum(case when 
order_rating is not null then 1
else 0 end)/count(*),2)>=50.00
order by average_rating desc,customer_id desc