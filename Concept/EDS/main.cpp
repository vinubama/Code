// Employee Management System for Inserting, Deleting, Modifying, Searching and Printing the elements in the EDS

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct EmployeData {
  int e_id;
  char e_name[50];
  char e_designation[100];
  int e_experiance_in_years;
  long int e_salary;
  int e_age;
  struct EmployeData *next;
} EData;

EData *e = NULL;

int search_id(int id);
void insertEmployeeData();
void printEmployeeData();
void searchEmployeeData(int e_id);
void deleteEmployeeData(int e_id);
void modifyEmployeeData(int e_id);

void printEmployeeData() {
  if(e == NULL) {
    cout << "EDS is empty" << endl;
    return;
  }
  EData *employee = e;

  while(employee != NULL) {
    printf("Employee Details for the Employee Id: %d\n", employee->e_id);
    cout << "Employee Name: " << employee->e_name << endl;
    cout << "Employee Designation: " << employee->e_designation << endl;
    cout << "Employee experiance: " << employee->e_experiance_in_years << endl;
    cout << "Employee Salary: " << employee->e_salary << endl;
    cout << "Employee Age: " << employee->e_age << endl;
    cout << "****************************************" << endl;
    employee = employee->next;
  }
}

int search_id(int id) {
  EData *employee = e;
  while(employee != NULL) {
    if(employee->e_id == id)
      return 0;
    employee = employee->next;
  }
  return 1;
}

void insertEmployeeData() {
  EData *employee = (EData*)malloc(sizeof(EData));

  int id;
  cout << "Enter Employee ID: ";
  cin >> id;
  if (!search_id(id)){
    cout << "This employee ID already exists in EMS. Exiting" << endl;
    return;
  } else {
    employee->e_id = id;
  }

  cout << "Enter Employee Name: ";
  cin >> employee->e_name;

  cout << "Enter Employee Designation: ";
  cin >> employee->e_designation;

  cout << "Enter Employee Experiance: ";
  cin >> employee->e_experiance_in_years;

  cout << "Enter Employee Salary: ";
  cin >> employee->e_salary;

  cout << "Enter Employee Age: ";
  cin >> employee->e_age;

  employee->next = e;
  e = employee;

  cout << "Inserted successfully !!!" << endl;
  return;
}

void searchEmployeeData(int e_id) {
  if(search_id(e_id)) {
    cout << "The Employee ID "<< e_id << " is not present in the EDS" << endl;
    return;
  }

  EData *employee = e;

  while(employee != NULL) {
    if(employee->e_id == e_id) {
      printf("Employee Details for the Employee Id: %d\n", employee->e_id);
      cout << "Employee Name: " << employee->e_name << endl;
      cout << "Employee Designation: "<< employee->e_designation << endl;
      cout << "Employee experiance: " << employee->e_experiance_in_years << endl;
      cout << "Employee Salary: " << employee->e_salary << endl;
      cout << "Employee Age: " << employee->e_age << endl;
      return;
    }
    employee = employee->next;
  }
}

void deleteEmployeeData(int e_id) {
  if(search_id(e_id)) {
    cout << "The Employee ID "<< e_id << " is not present in the EDS" << endl;
    return;
  }

  EData *employee = e;
  EData *next_data = e->next;

  // If to delete first entry in EDS
  if (employee->e_id == e_id) {
    e = e->next;
    free(employee);
    return;
  }

  while(next_data != NULL) {
    if(next_data->e_id == e_id) {
      employee->next = next_data->next;
      free(next_data);
      return;
    }
    employee = employee->next;
    next_data = next_data->next;
  }
}

void modifyEmployeeData(int e_id) {
  if(search_id(e_id)) {
    cout << "The Employee ID "<< e_id << " is not present in the EDS" << endl;
    return;
  }

  EData *employee = e;
  while(employee != NULL) {
    if(employee->e_id == e_id) {
      int input;
      do {
        cout << "****************************************" << endl;
        cout << "Enter which data to modify" << endl;
        cout << "1. Name\n2.Designation\n3.Experiance\n4.Salary\n5.Age\n6.Exit"
             << endl;
        cin >> input;
        switch(input){
          case 1:
            cout << "Employee Name: ";
            cin >> employee->e_name;
            break;
          case 2:
            cout << "Employee Designation: ";
            cin >> employee->e_designation;
            break;
          case 3:
            cout << "Employee Experiance:";
            cin >> employee->e_experiance_in_years;
            break;
          case 4:
            cout << "Employee Salary:";
            cin >> employee->e_salary;
            break;
          case 5:
            cout << "Employee Age: ";
            cin >> employee->e_age;
            break;
          case 6:
          default:
            return;
        }
      } while (1);
      employee = employee->next;
    }
  }

}
int main() {

  int input;  
  do
  {
    cout << "************Enter your choice***********" << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. Delete Data" << endl;
    cout << "3. Print Data" << endl;
    cout << "4. Search Data" << endl;
    cout << "5. Modify Data" << endl;
    cout << "6. Exit" << endl;
    cout << "****************************************" << endl;
    cin >> input;

    switch(input) {
      case 1:
        cout << "Inserting data" << endl;
        insertEmployeeData();
        cout << "***********************************************************" << endl;
        break;
      case 2:
        cout << "Enter the Employee ID to delete: ";
        int emp_id_delete;
        cin >> emp_id_delete;
        deleteEmployeeData(emp_id_delete);
        cout << "***********************************************************" << endl;
        break;
      case 3:
        cout << "Printing Elements in the EMS" << endl;
        printEmployeeData();
        cout << "***********************************************************" << endl;
        break;
      case 4:
        cout << "Enter the Employee ID to search: ";
        int id_to_search;
        cin >> id_to_search;
        searchEmployeeData(id_to_search);
        cout << "***********************************************************" << endl;
        break;
      case 5:
        cout << "Enter the Employee ID to modify: ";
        int id_to_modify;
        cin >> id_to_modify;
        modifyEmployeeData(id_to_modify);
        break;
      case 6:
      default:
        exit(0);
      }
  } while (1);

  return 0;
}

