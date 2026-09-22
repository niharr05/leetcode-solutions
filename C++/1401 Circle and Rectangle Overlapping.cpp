#include <algorithm>

class Solution {
public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                    int x2, int y2) {
    // Find the point inside/on the rectangle closest to the circle's center
    int nearestX = std::max(x1, std::min(xCenter, x2));
    int nearestY = std::max(y1, std::min(yCenter, y2));

    // Calculate squared distance between circle center and the nearest point
    int dx = xCenter - nearestX;
    int dy = yCenter - nearestY;

    return (dx * dx + dy * dy) <= (radius * radius);
  }
};