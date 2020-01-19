__________________________________________________________________________________________________
sample 272 ms submission
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        seen = set([id])
        current = [id]
        
        while level:
            frontier = []
            for person in current:
                news = friends[person]
                for new in news:
                    if new not in seen:
                        frontier.append(new)
                        seen.add(new)
            current = frontier 
            
            level -= 1
        videos = []
        for person in current:
            videos.extend(watchedVideos[person])
        c = collections.Counter(videos)
        return sorted(c, key = lambda video: (c[video],video))
__________________________________________________________________________________________________
sample 276 ms submission
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        people, visited, video_count = {id}, {id}, dict()
        for i in range(level):
            people = set(itertools.chain(*[friends[x] for x in people])) - visited
            visited |= people
        for person in people:
            for video in watchedVideos[person]:
                if video in video_count: video_count[video] += 1
                else: video_count[video] = 1
        return sorted(video_count, key = lambda x: (video_count[x], x))
__________________________________________________________________________________________________
