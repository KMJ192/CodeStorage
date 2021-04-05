#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

//class Employee {
//private:
//    int id;
//    int importance;
//    vector<int> subordinates;
//    
//public:
//    Employee(int id, int importance, vector<int> subordinates) {
//        this->id = id;
//        this->importance = importance;
//        this->subordinates = subordinates;
//    }
//    int getId() {
//        return id;
//    }
//    int getImportance() {
//        return importance;
//    }
//    vector<int> getSub() {
//        return subordinates;
//    }
//};

//class Solution {
//public:
//    int getImportance(vector<Employee*> employees, int id) {
//        int importance = 0;
//        vector<int> subordinate;
//        for (int i = 0; i < employees.size(); i++) {
//            if (id != employees[i]->getId()) continue;
//
//            //중요도 합
//            importance += employees[i]->getImportance();
//            
//            
//            for (int j = 0; j < employees[i]->getSub().size(); j++) {
//                subordinate.push_back(employees[i]->getSub()[j]);
//            }
//            break;
//        }
//        for (int i = 0; i < subordinate.size(); i++) {
//            for (int j = 0; j < employees.size(); j++) {
//                if (subordinate[i] != employees[j]->getId()) continue;
//
//                importance += employees[j]->getImportance();
//            }
//        }
//        
//        return importance;
//    }
//};

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importance = 0;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id != id) continue;
            if (employees[i]->subordinates.size() == 0) {
                return employees[i]->importance;
            }
            importance = getSub(employees, i, importance, 0);
            break;
        }
        return importance;
    }

    int getSub(vector<Employee*> employees, int id, int total, int depth) {
        if (employees[id]->subordinates.size() == 0) {
            if(depth > 0) total += employees[id]->importance;
            return total;
        }
        int hap = 0;
        depth++;
        for (int i = 0; i < employees[id]->subordinates.size(); i++){
            if (i > 0) {
                depth++;
                hap += getSub(employees, employees[id]->subordinates[i] - 1, total, depth);
            }
            else {
                hap += getSub(employees, employees[id]->subordinates[i] - 1, total + employees[id]->importance, depth);
            }
            depth = 0;
        }
        return hap;
    }
};


int main() {
    vector<vector<int>> subordinates = {
        {2, 3},
        {4},
        {},
        {}
    };
    Employee* first = new Employee;
    first->id = 1; first->importance = 5; first->subordinates = subordinates[0];

    Employee* second = new Employee;
    second->id = 2; second->importance = 3; second->subordinates = subordinates[1];

    Employee* third = new Employee;
    third->id = 3; third->importance = 4; third->subordinates = subordinates[2];

    Employee* forth = new Employee;
    forth->id = 4; forth->importance = 1; forth->subordinates = subordinates[3];
    
    vector<Employee*> vEmp;
    vEmp.push_back(first);
    vEmp.push_back(second);
    vEmp.push_back(third);
    vEmp.push_back(forth);

    Solution solution;
    cout << solution.getImportance(vEmp, 1);

    delete first;
    delete second;
    delete third;
    delete forth;
    
    return 0;
}