// Leetcode 2069. Walking Robot Simulation II


#include <bits/stdc++.h>
using namespace std;

class Robot {
public:
    int idx = 0;              // current index in perimeter path
    bool moved = false;      // to handle initial direction case
    vector<vector<int>> pos; // stores {x, y, direction}

    /*
        Constructor:
        Precompute all boundary positions of the grid
        along with direction at that position.
        
        Direction mapping:
        0 -> East
        1 -> North
        2 -> West
        3 -> South
    */
    Robot(int width, int height) {

        // Bottom Row (left → right) → East (0)
        for (int x = 0; x < width; x++) {
            pos.push_back({x, 0, 0});
        }

        // Right Column (bottom → top) → North (1)
        for (int y = 1; y < height; y++) {
            pos.push_back({width - 1, y, 1});
        }

        // Top Row (right → left) → West (2)
        for (int x = width - 2; x >= 0; x--) {
            pos.push_back({x, height - 1, 2});
        }

        // Left Column (top → bottom) → South (3)
        for (int y = height - 2; y > 0; y--) {
            pos.push_back({0, y, 3});
        }

        // Special handling:
        // When robot returns to (0,0), direction should be South
        pos[0][2] = 3;
    }
    
    // Move robot 'num' steps
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    // Get current position
    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }
    
    // Get current direction as string
    string getDir() {
        if (!moved)
            return "East"; // initial direction
        
        int d = pos[idx][2];

        if (d == 0) return "East";
        else if (d == 1) return "North";
        else if (d == 2) return "West";
        return "South";
    }
};


int main() {
    int width, height;
    cout << "Enter width and height: ";
    cin >> width >> height;

    Robot obj(width, height);

    int q;
    cout << "Enter number of steps queries: ";
    cin >> q;

    while (q--) {
        int steps;
        cout << "\nEnter steps: ";
        cin >> steps;

        obj.step(steps);

        vector<int> pos = obj.getPos();
        string dir = obj.getDir();

        cout << "Position: (" << pos[0] << ", " << pos[1] << ")\n";
        cout << "Direction: " << dir << "\n";
    }

    return 0;
}