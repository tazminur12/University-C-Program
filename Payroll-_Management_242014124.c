#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct employee
{
    int id;
    char name[100];
    int salary;
    struct employee*next;
} employee;
employee *head=NULL;
void addemployee(int id,char name[],int salary){
    employee* newemp =(employee*)malloc(sizeof(employee));
    newemp->id=id;
    strcpy(newemp->name,name);
    newemp->salary=salary;
    newemp->next=NULL;
    if(head==NULL){
        head=newemp;
    }
    else{
        employee* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newemp;
    }
    printf("New employee added\n");
}
void deleteEmployee(int id){
    employee *temp=head, *prev=NULL;
    while(temp!=NULL && temp->id!=id){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Employee with %d ID not found\n",id);
        return;
    }
    if(prev==NULL){
        head=head->next;
    }
    else{
        prev->next=temp->next;
    }
    free(temp);
    printf("Employee with %d ID deleted successfully\n",id);
}
void search(int id){
    employee*temp=head;
    while(temp!=NULL){
        if(temp->id==id){
            printf("Employee found: ID=%d, Name=%s, Salary=%d\n", temp->id, temp->name, temp->salary);
            return;
        }temp=temp->next;
        }
        printf("Employee ID %d not found.\n", id);
}
void sort(employee**arr,int count){
    for(int i=1;i<count;i++){
            employee*key=arr[i];
            int j=i-1;
            while(j>=0&&arr[j]->id>key->id){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
    }
}
void display(){
    if(head==NULL){
         printf("No employees to display.\n");
        return;
    }
    int count=0;
    employee*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    employee** arr=malloc(count* sizeof(employee*));
    temp=head;
    for(int i=0;i<count;i++){
        arr[i]=temp;
        temp=temp->next;
    }
    sort(arr,count);
    printf("Employee List (Sorted by ID):\n");
    printf("----------------------------------------------------\n");
    printf("ID\t\tName\t\t\tSalary\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%d\n", arr[i]->id, arr[i]->name, arr[i]->salary);
    }
     printf("----------------------------------------------------\n");

    free(arr);
}
int main() {
    int choice, empID, salary;
    char name[100];
    printf("\n Employee Payroll Management\n");

    while (1) {
        printf("***********************************\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee by ID\n");
        printf("3. Search Employee by ID\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n");
        printf("***********************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &empID);
                getchar();
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter Salary: ");
                scanf("%d", &salary);
                addemployee(empID, name, salary);
                break;
            case 2:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &empID);
                deleteEmployee(empID);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &empID);
                search(empID);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

