from collections import defaultdict

class Solution:
    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        graph = defaultdict(list)
        for src, dst in tickets:
            graph[src].append(dst)
        
        for src in graph:
            graph[src].sort(reverse=True)
            
        itinerary = []
        
        def dfs(airport):
            while graph[airport]:
                next_airport = graph[airport].pop()
                dfs(next_airport)
            itinerary.append(airport)
            
        dfs("JFK")
        return itinerary[::-1]
