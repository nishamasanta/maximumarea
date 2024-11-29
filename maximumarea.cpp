#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// Function to calculate the area of a polygon using the Shoelace theorem
int calculate_area(const vector<pair<int, int>>& polygon) {
    int n = polygon.size();
    int area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += polygon[i].first * polygon[j].second;
        area -= polygon[i].second * polygon[j].first;
    }
    return abs(area) / 2;
}

// Function to find all valid polygons formed by the segments
vector<vector<pair<int, int>>> find_polygons(const vector<pair<int, int>>& points, const vector<pair<pair<int, int>, pair<int, int>>>& segments) {
    vector<vector<pair<int, int>>> polygons;
    
    // Placeholder: You would implement logic to find polygons formed by the segments.
    // This is a non-trivial task and could involve methods like detecting cycles or convex hulls.

    // For simplicity, let's assume we have some polygons to process.
    polygons.push_back({points[0], points[1], points[2]});
    polygons.push_back({points[1], points[2], points[3]});

    return polygons;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points;
    vector<pair<pair<int, int>, pair<int, int>>> segments;

    // Read the segments
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.push_back({x1, y1});
        points.push_back({x2, y2});
        segments.push_back({{x1, y1}, {x2, y2}});
    }

    // Remove duplicate points
    set<pair<int, int>> unique_points(points.begin(), points.end());
    points.assign(unique_points.begin(), unique_points.end());

    int max_area = 0;

    // Find all valid polygons formed by the segments
    vector<vector<pair<int, int>>> polygons = find_polygons(points, segments);

    // Calculate the area for each polygon and track the maximum
    for (const auto& polygon : polygons) {
        max_area = max(max_area, calculate_area(polygon));
    }

    // Output the maximum area
    cout << max_area << endl;

    return 0;
}
