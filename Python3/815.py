__________________________________________________________________________________________________
sample 400 ms submission
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        #BFS: traverse all bus stop that are reachable by all the bus route that go via the Start
        if S == T: 
            return 0
        # need to record all the routes you can take at each stop so that you can find all 
        # the stops you can reach when you take one time of bus
        stop_routes = {}
        for route, stops in enumerate(routes):
            for stop in stops:
                if stop not in stop_routes:
                    stop_routes[stop] = [route]
                else:
                    stop_routes[stop].append(route)
        # record all the stops you can reach when you take one time bus route
        queue = collections.deque([S])
        # record route has been taken before
        visited = set()
        countRoute = 0
        while queue:
            countRoute += 1
            # all stops you can reach last time
            prev_stops = len(queue)
            for _ in range(prev_stops):
                curStop = queue.popleft()
                for route in stop_routes[curStop]:
                    if route not in visited:
                        visited.add(route)
                        for stop in routes[route]:
                            if stop == T:
                                return countRoute
                            queue.append(stop)
        return -1
__________________________________________________________________________________________________
sample 408 ms submission
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        M = max(map(max, routes))
        coroute = [[] for _ in range(M+1)]
        for k, r in enumerate(routes):
            for ri in r:
                coroute[ri].append(k)
                
        old_routes = set()

        print('arrows ok')
        
        n_steps = 0
        old = set()
        at = set([S])
        while T not in at:
            print(f'step {n_steps}')
            old.update(at)
            
            to = set()
            for i in at:
                for rt in coroute[i]:
                    if rt in old_routes:
                        continue
                    to.update(routes[rt])
                    old_routes.add(rt)
            new = to - old
            #print("new",new)
            
            if len(new) == 0:
                return -1            
            n_steps += 1
            at = new
        return n_steps
__________________________________________________________________________________________________
