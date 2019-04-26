__________________________________________________________________________________________________
class Solution {
public:
    static bool pointCompare(const Point& a, const Point& b) {
        //Sort the points by x-coordinates, break a tie by y-coordinate
        return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
    }
    
    bool isEqual(const Point& a, const Point& b) {
        return (a.x == b.x) && (a.y == b.y);    
    }
    
    int crossProduct(const Point& a, const Point& b, const Point& c) {
        // > 0 if a,b,c forms a counter clockwise turn
        // < 0 if a,b,c forms a clockwise turn
        // = 0 if a,b,c are collinear
        return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    }
    
    vector<Point> outerTrees(vector<Point>& points) {
        //Sort the points
        sort(points.begin(), points.end(), pointCompare);
        vector<Point> upper;
        vector<Point> lower;
        //Find upper hull, in the dereasing order of x-coordinate
        for (int i = points.size() - 1; i >= 0; --i) {
            //Pop the top point if next_to_top, top, points[i] forms a right turn (in clockwise turn)
            while ((upper.size() > 1) 
                && (crossProduct(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) < 0)) {
                upper.pop_back();
            }
            upper.push_back(points[i]);
        }
        //Find lower hull, in the increasing order of x-coordinate 
        for (int i=0; i<points.size(); i++) {
            //Pop the top point if next_to_top, top, points[i] forms a right turn (in clockwise turn)
            while ((lower.size() > 1) 
                && (crossProduct(lower[lower.size() - 2], lower[lower.size() - 1], points[i]) < 0)) {
                lower.pop_back();
            }
            lower.push_back(points[i]);            
        }
        //Check the degenerate case if the convex hull is a line
        //In this case, lower == upper, we only need to check if upper[1] == lower[lower.size() - 2]
        if ((points.size() == 1) || (isEqual(upper[1],lower[lower.size() - 2]))) {
            return vector<Point>(upper.begin(), upper.end());
        }
        //In non-degenerate case, remove the starting point for both hulls
        //The right most one and the left most one is duplicated in both hulls
        vector<Point> vertices(upper.begin() + 1, upper.end());
        vertices.insert(vertices.end(), lower.begin() + 1, lower.end());
        return vertices;
    }
};
__________________________________________________________________________________________________
class Solution {
 public:
  typedef int coord_t;  // coordinate type
  typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
  // 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross
  // product. Returns a positive value, if OAB makes a counter-clockwise turn,
  // negative for clockwise turn, and zero if the points are collinear.
  coord2_t cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (coord2_t)(B.y - O.y) -
           (A.y - O.y) * (coord2_t)(B.x - O.x);
  }

  static bool cmp(Point &p1, Point &p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
  }

  static bool equ(Point &p1, Point &p2) { return p1.x == p2.x && p1.y == p2.y; }
  // Returns a list of points on the convex hull in counter-clockwise order.
  // Note: the last point in the returned list is the same as the first one.
  vector<Point> outerTrees(vector<Point> &P) {
    int n = P.size(), k = 0;
    vector<Point> H(2 * n);

    // Sort points lexicographically
    sort(P.begin(), P.end(), cmp);

    // Build lower hull
    for (int i = 0; i < n; i++) {
      while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
      while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
    }

    // Remove duplicates
    H.resize(k);
    sort(H.begin(), H.end(), cmp);
    H.erase(unique(H.begin(), H.end(), equ), H.end());
    return H;
  }
};
__________________________________________________________________________________________________
