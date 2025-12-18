#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int studentID; 
    char name[50]; 
    struct Student *left, *right; 

}Student; 

Student* createNode(int studentID, char* name ){
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->studentID = studentID; 
    strcpy(newStudent->name, name); 
    newStudent->left = newStudent->right = NULL; 
    return newStudent; 
}


Student* insert (Student* root, int studentID, char* name) {

if (root == NULL) return createNode (studentID, name);

if (studentID < root->studentID)
    root->left = insert (root->left, studentID, name);

else if (studentID > root->studentID)

    root->right = insert (root->right, studentID, name);
else

    printf("Student with student ID %d already exists.\n", studentID);
    return root; 

}

void inorderTraversal (Student* root) {
if (root != NULL) {
    inorderTraversal (root->left);
        printf("Student ID: %d, Name: %s\n", root->studentID, root->name);

    inorderTraversal(root->right);
}
} 
//
Student* search (Student* root, int studentID) {

    if (root == NULL || root->studentID == studentID) return root;
    if (studentID < root->studentID) return search (root->left, studentID);
    return search (root->right, studentID);
}

Student* findMin (Student* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Student* deleteNode (Student* root, int studentID) {
    if (root == NULL) return root;

    if (studentID < root->studentID)
        root->left = deleteNode(root->left, studentID);
    else if (studentID > root->studentID)
        root->right = deleteNode(root->right, studentID);
    else {
        if (root->left == NULL) {
            Student* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Student* temp = root->left;
            free(root);
            return temp;
        }

        Student* temp = findMin(root->right);
        root->studentID = temp->studentID;
        strcpy(root->name, temp->name);
        root->right = deleteNode(root->right, temp->studentID);
    }

    return root;   
}


// 
///////

int main() {
    Student* root = NULL;
    int choice, studentID;
    char name[50];
    ;

    do {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");

    printf("3. Search Student \n");
    printf("4. Delete Student \n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Enter student ID: ");
        scanf("%d", &studentID);
        printf("Enter Name: ");
        scanf("%s", name);
        root = insert(root, studentID, name);
        break;

    case 2:
        printf("\n--- Student Records ---\n");
        inorderTraversal (root);
        break;
    case 3:
    {

    
        printf("Enter student ID to Search: ");
        scanf("%d", &studentID);
        Student* found = search(root, studentID);
    if (found != NULL)
        printf("Record Found: student ID : %d, Name: %s", found->studentID, found->name); 
       else 
            printf("Record not found.\n"); 
        break;
    }
    case 4:
    {


        printf("Enter student ID to Delete: ");
        scanf("%d", &studentID);
        root = deleteNode (root, studentID);
        printf("Record deleted if it existed.\n");
        break;
    }
    case 5:
    {
        printf("Exiting...\n");
    
        default:
        
        printf("Invalid choice! Please try again.\n");
    
    }
}

   } while (choice != 5);

    
    
    return 0;
} 
    

  