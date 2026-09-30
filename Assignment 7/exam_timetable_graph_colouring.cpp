#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Room {
    string name;
    int capacity;
};

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    if (!(cin >> numCourses)) return 0;

    vector<string> courses(numCourses);
    map<string, int> courseIndex;
    cout << "Enter course codes:\n";
    for (int i = 0; i < numCourses; i++) {
        cin >> courses[i];
        courseIndex[courses[i]] = i;
    }

    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    vector<int> studentCount(numCourses, 0);
    vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));

    cout << "Enter student enrollments (student_id count course1 course2 ...):\n";
    for (int i = 0; i < numStudents; i++) {
        string sId;
        int count;
        cin >> sId >> count;
        vector<int> enrolled;
        for (int j = 0; j < count; j++) {
            string cCode;
            cin >> cCode;
            if (courseIndex.find(cCode) != courseIndex.end()) {
                int cIdx = courseIndex[cCode];
                studentCount[cIdx]++;
                enrolled.push_back(cIdx);
            }
        }
        for (size_t a = 0; a < enrolled.size(); a++) {
            for (size_t b = a + 1; b < enrolled.size(); b++) {
                int u = enrolled[a];
                int v = enrolled[b];
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
        }
    }

    int numRooms;
    cout << "Enter number of available classrooms: ";
    cin >> numRooms;

    vector<Room> rooms(numRooms);
    cout << "Enter room name and capacity:\n";
    for (int i = 0; i < numRooms; i++) {
        cin >> rooms[i].name >> rooms[i].capacity;
    }

    vector<int> degree(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < numCourses; j++) {
            if (adj[i][j]) degree[i]++;
        }
    }

    vector<int> order(numCourses);
    for (int i = 0; i < numCourses; i++) order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b) {
        return degree[a] > degree[b];
    });

    vector<int> color(numCourses, -1);
    for (int idx = 0; idx < numCourses; idx++) {
        int u = order[idx];
        vector<bool> used(numCourses + 1, false);
        for (int v = 0; v < numCourses; v++) {
            if (adj[u][v] && color[v] != -1) {
                used[color[v]] = true;
            }
        }
        int assignedColor = 0;
        while (used[assignedColor]) assignedColor++;
        color[u] = assignedColor;
    }

    int maxColor = 0;
    for (int i = 0; i < numCourses; i++) {
        maxColor = max(maxColor, color[i]);
    }

    cout << "\nExam Timetable Schedule:\n";
    cout << "Total Time Slots Required: " << (maxColor + 1) << "\n\n";

    vector<string> assignedRoom(numCourses, "Unassigned");

    for (int slot = 0; slot <= maxColor; slot++) {
        vector<int> slotCourses;
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == slot) slotCourses.push_back(i);
        }

        sort(slotCourses.begin(), slotCourses.end(), [&](int a, int b) {
            return studentCount[a] > studentCount[b];
        });

        vector<bool> roomOccupied(numRooms, false);

        for (int cIdx : slotCourses) {
            int needed = studentCount[cIdx];
            int bestRoom = -1;
            int minCapacityFit = 1e9;

            for (int r = 0; r < numRooms; r++) {
                if (!roomOccupied[r] && rooms[r].capacity >= needed) {
                    if (rooms[r].capacity < minCapacityFit) {
                        minCapacityFit = rooms[r].capacity;
                        bestRoom = r;
                    }
                }
            }

            if (bestRoom != -1) {
                assignedRoom[cIdx] = rooms[bestRoom].name;
                roomOccupied[bestRoom] = true;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) {
        cout << "Course: " << courses[i]
             << " -> Time Slot: Slot " << (color[i] + 1)
             << " -> Room: " << assignedRoom[i]
             << " (Students: " << studentCount[i] << ")\n";
    }

    return 0;
}
