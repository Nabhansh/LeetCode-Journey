#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function to compare integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Helper function to count common elements using two pointers
int get_intersection_size(int* a, int a_size, int* b, int b_size) {
    int i = 0, j = 0;
    int count = 0;
    while (i < a_size && j < b_size) {
        if (a[i] == b[j]) {
            count++;
            // Move past duplicates to count only distinct common integers
            int val = a[i];
            while (i < a_size && a[i] == val) i++;
            while (j < b_size && b[j] == val) j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return count;
}

// DFS to mark all nodes in the current component as visited
void dfs(int node, int n, bool** adj, bool* visited) {
    visited[node] = true;
    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (adj[node][neighbor] && !visited[neighbor]) {
            dfs(neighbor, n, adj, visited);
        }
    }
}

int numberOfComponents(int** properties, int propertiesSize, int* propertiesColSize, int k) {
    int n = propertiesSize;
    int m = propertiesColSize[0];

    // Step 1: Sort each row to allow O(m) intersection check
    for (int i = 0; i < n; i++) {
        qsort(properties[i], m, sizeof(int), compare);
    }

    // Step 2: Build adjacency matrix
    bool** adj = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        adj[i] = (bool*)calloc(n, sizeof(bool));
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (get_intersection_size(properties[i], m, properties[j], m) >= k) {
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }

    // Step 3: Find Connected Components using DFS
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int componentsCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            componentsCount++;
            dfs(i, n, adj, visited);
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);

    return componentsCount;
}
