__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
       int n = asteroids.length;
        int j = -1;
        for (int i = 0; i < n; i++) {
            asteroids[++j] = asteroids[i];
            if (asteroids[i] < 0) {
                while (j >= 1) {
                    int r = asteroids[j], l = asteroids[j - 1];
                    if (l > 0 && r < 0) {
                        if (l > -r) {--j;break;}
                        else if (l < -r) asteroids[--j] = r;
                        else j = j - 2;
                    } else {
                        break;
                    }
                }
            }
        }
        return Arrays.copyOfRange(asteroids, 0, j + 1);
    }
}
__________________________________________________________________________________________________
sample 36832 kb submission
class Solution {
    public static int[] asteroidCollision(int[] asteroids) {
       ArrayDeque<Integer> asteroid = new ArrayDeque<>();
        if (asteroids.length > 0) {

            for (int i = 0; i < asteroids.length; i++) {
                if(asteroid.size() == 0){
                    asteroid.addLast(asteroids[i]);
                    continue;
                }

                if (asteroids[i] > 0) {
                    asteroid.addLast(asteroids[i]);
                    continue;
                }

                if (asteroids[i] < 0 && asteroid.peekLast() < 0) {
                    asteroid.addLast(asteroids[i]);
                    continue;
                }

                if (asteroids[i] < 0 && asteroid.peekLast() + asteroids[i] == 0) {
                    asteroid.pollLast();
                    continue;
                }

                if (asteroids[i] < 0 && asteroid.peekLast() > 0) {
                    if (asteroids[i] + asteroid.peekLast() > 0) {
                        continue;
                    } else {
                        while (asteroid.size() > 0 && asteroid.peekLast() > 0 && asteroid.peekLast() + asteroids[i] < 0) {
                            asteroid.pollLast();
                        }

                        if(asteroid.size() == 0){
                            asteroid.addLast(asteroids[i]);
                            continue;
                        }

                        if(asteroid.peekLast() < 0){
                            asteroid.addLast(asteroids[i]);
                            continue;
                        }

                        if (asteroid.peekLast() + asteroids[i] == 0 && asteroid.size() > 0) {
                            asteroid.pollLast();
                            continue;
                        }

                        if (asteroid.peekLast() + asteroids[i] > 0) {
                            continue;
                        }
                    }
                }
            }
        }

        return asteroid.stream()
                .mapToInt(element -> element)
                .toArray();
    }
}

__________________________________________________________________________________________________
