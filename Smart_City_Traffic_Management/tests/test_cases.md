# Test cases

| ID | Operation | Input | Expected result |
|---|---|---|---|
| TC01 | Shortest route | Central Station → Airport | Route: Central Station → Tech Park → University → Airport; 26 minutes (or another equal-cost route if graph changes) |
| TC02 | Shortest route | Central Station → City Hospital | Central Station → City Hospital; 8 minutes |
| TC03 | Congestion update | Central Station ↔ Tech Park = 30 | Update accepted; subsequent shortest route is recalculated |
| TC04 | BFS | Start at Central Station | All seven demo locations are reachable |
| TC05 | Invalid location | Unknown → Airport | Clear unknown-source/destination message |
| TC06 | Invalid weight | Update road with 0 or negative time | Update rejected |
| TC07 | Invalid menu | Enter non-numeric input | Program recovers and displays menu again |
| TC08 | Same source/destination | Airport → Airport | Airport; 0 minutes |

Note: The demo graph is undirected and connected. Test expected route cost rather than requiring a single route when multiple routes have the same minimum cost.
