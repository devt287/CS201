#include "employee.h"




EMPLOYEE* list_of_employees=NULL;
void printEmployee(EMPLOYEE e){
    printf("Name: %s, ", e.name);
    printf("ID: %d\n", e.id);
    PAYMENT* temp=e.payments;
    if (temp) {
        printf("------------------------\n"); 
        printf("Date       |Amount\n");
        printf("----       |-----\n"); 
        while (temp) {
            printf("%s |%.6f\n", temp->date, temp->amount); 
            temp=temp->next;
        }
    } else {
        printf("No Payments..\n");
    }
    
}


void addEmployee(int e_id, char* e_name){
    // Your code here
    EMPLOYEE* new_employee = (EMPLOYEE*)malloc(sizeof(EMPLOYEE));
    new_employee->id=e_id;
    new_employee->name=e_name;
    new_employee->payments=NULL;
    new_employee->next=list_of_employees;
    list_of_employees=new_employee;
}

void printEmployees(){
    // Your code here
    EMPLOYEE* temp =list_of_employees;
    if(temp==NULL){
        printf("This list is empty..\n");
    }
    while(temp!=NULL){
        printEmployee(*temp);
        printf("==========================\n"); 
        temp=temp->next;
    }

}

int addPayment(int e_id, char* p_date, float p_amount){
    // Your code here
    EMPLOYEE*temp=list_of_employees;
    while(temp!=NULL){
        if(temp->id==e_id){
            PAYMENT*new_payment=(PAYMENT*)malloc(sizeof(PAYMENT));
            new_payment->date=p_date;
            new_payment->amount=p_amount;
            new_payment->next=temp->payments;
            temp->payments=new_payment;
            return 1;
        }
        temp=temp->next;
    }
    return 0;

}

int deleteEmployee(int e_id, char* e_name){
    // Your code here
    EMPLOYEE*temp=list_of_employees;
    EMPLOYEE*prev=NULL;
    while(temp!=NULL){
        if(temp->id==e_id){
            if(prev==NULL){
                list_of_employees=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            free(temp);
            return 1;
        }
        prev=temp;
        temp=temp->next;
    }
    return 0;

}


