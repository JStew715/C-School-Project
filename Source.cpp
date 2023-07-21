#include <iostream>
#include <string>

// Creating the employee class info and identifiers 
class EmployeeInfo {
public:
    int id;
    std::string name;

    EmployeeInfo(int id, const std::string& name)
        : id(id), name(name) {}
};

// Creating the Treenode class 
class TreeNode {
public:
    EmployeeInfo* employee;
    TreeNode* left;
    TreeNode* right;

    TreeNode(EmployeeInfo* emp)
        : employee(emp), left(NULL), right(NULL) {}

    ~TreeNode() {
        delete employee;
        delete left;
        delete right;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    void insertNode(TreeNode*& node, EmployeeInfo* emp) {
        if (node == NULL) {
            node = new TreeNode(emp);
        }
        else if (emp->id < node->employee->id) {
            insertNode(node->left, emp);
        }
        else {
            insertNode(node->right, emp);
        }
    }
// Function to search for a node using the ID number
    TreeNode* searchNode(TreeNode* node, int id) {
        if (node == NULL || node->employee->id == id) {
            return node;
        }

        if (id < node->employee->id) {
            return searchNode(node->left, id);
        }
        else {
            return searchNode(node->right, id);
        }
    }

public:
    BinaryTree()
        : root(NULL) {}

    ~BinaryTree() {
        delete root;
    }

// Inserting a node into the binary tree
    void insert(EmployeeInfo* emp) {
        insertNode(root, emp);
    }

    std::string search(int id) {
        TreeNode* node = searchNode(root, id);
        if (node != NULL) {
            return node->employee->name;
        }
        else {
            return "No results";
        }
    }
};

int main() {
    BinaryTree tree;

// Inputting all the employee info into the binary tree
    tree.insert(new EmployeeInfo(1021, "John Williams"));
    tree.insert(new EmployeeInfo(1057, "Bill Witherspoon"));
    tree.insert(new EmployeeInfo(2487, "Jennifer Twain"));
    tree.insert(new EmployeeInfo(3769, "Sophia Lancaster"));
    tree.insert(new EmployeeInfo(1017, "Debbie Reece"));
    tree.insert(new EmployeeInfo(1275, "George McMullen"));
    tree.insert(new EmployeeInfo(1899, "Ashley Smith"));
    tree.insert(new EmployeeInfo(4218, "Josh Plemmons"));

// Ask the user to enter an employee ID
    std::cout << "Enter an employee ID to search: ";
    int searchID;
    std::cin >> searchID;

 // Display the result
    std::string result = tree.search(searchID);
    std::cout << "Search Result: " << result << std::endl;

    return 0;
}