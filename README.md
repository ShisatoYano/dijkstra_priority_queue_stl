# dijkstra_priority_queue_stl

* Find shortest path using priority queue of STL.  
* Recommended to use heap or priority queue as required operations.  
* Extract minimum and decrease key  
* Priority queue doesn't support decrease key.  

1. Initialize distance of all vertices as infinite.  
2. Create an empty priority queue(pq)
3. Every item of pq is a pair(weight, vertex)
4. Insert source vertex into pq and make its distance as 0.
5. While either pq doesn't become empty
6. Extract minimum distance vertex from pq. Let the extracted vertex be u.
7. Loop through all adjacent of u and do following for every vertex v.
8. if dist[v] > dist[u] + weight(u, v)
9. update distance of v, do dist[v] = dist[u] + weight(u, v)
10. Insert v into the pq even if v is already there
11. print distance array dist[] to print all shortest paths
