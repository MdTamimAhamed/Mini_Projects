//This is my first project - Topic : To Do List using "Singly Linked List"
#include <iostream>
#include <string>
#include <cstdlib>
#define MAX_TODO_SIZE 300

//create struct type variable
struct toDoList{
    char getToDo[MAX_TODO_SIZE];
    struct toDoList *nextNode;
};
typedef struct toDoList list;

//function references
void welcomeScreen();
void createNewToDo(list**);
void displayList(list**);
void countToDo(list**);
void deleteToDo(list**);
void updateToDo(list**);

int main(){
    list *head = NULL;
    welcomeScreen();
    while(true){
        int selectOption;
        system("color 0F");
        system("cls");
        std::cout <<"\n\n\n\n";
        std::cout <<"\t\t\tTo Do Menu:\n";
        std::cout <<"\t\t============================\n";
        std::cout <<"\t\t| 1.See To-Dos             |\n";
        std::cout <<"\t\t| -------------------------|\n";
        std::cout <<"\t\t| 2.Create New To Do List  |\n";
        std::cout <<"\t\t| -------------------------|\n";
        std::cout <<"\t\t| 3.Delete To Dos          |\n";
        std::cout <<"\t\t| -------------------------|\n";
        std::cout <<"\t\t| 4.Update To Dos          |\n";
        std::cout <<"\t\t| -------------------------|\n";
        std::cout <<"\t\t| 5.Exit                   |\n";
        std::cout <<"\n\n";

        std::cout <<"\t\tSelect your option <1-5>: ";
        std::cin >> selectOption;
        switch(selectOption){
            case 1:
                displayList(&head);
                break;
            case 2:
                createNewToDo(&head);
                break;
            case 3:
                deleteToDo(&head);
                break;
            case 4:
                updateToDo(&head);
                break;
            case 5:
                exit(0);
                break;
            default:
                std::cout << "\n\t\tWrong input.Try again!\n";
        }
        system("pause");
    }

}

void welcomeScreen(){
    system("color 0F");
    std::cout <<"\n\n\n\n";
    std::cout << "\t\t-------------------------------\n";
    std::cout << "\t\t|                             |\n";
    std::cout << "\t\t|\tWelcome to the        |\n";
    std::cout << "\t\t|\t--To Do List--        |\n";
    std::cout << "\t\t|                             |\n";
    std::cout << "\t\t-------------------------------\n";
    std::cout <<"\n\n\n\n";  
    system("pause");
}

void displayList(list **head_ref){
    system("cls");
    list * temp;
    if((*head_ref) == NULL){
        std::cout << "\n\n\n\n";
        std::cout << "\t\tYour To-Dos:\n";
        std::cout << "\t\t-------------------------------\n";
        std::cout << "\t\tList is empty!\n";
        std::cout << "\n\n\n\n";
    }
    else{
        countToDo(head_ref);
    }
}

void createNewToDo(list **head_ref){
    system("cls");
    list *firstNode, *lastNode;
    int countTopic = 1;
    char choice;

    std::cout << "\n\n\n\n";
    std::cout << "\t\tCreate New To-Dos:\n";
    std::cout << "\t\t----------------------\n\n";
    std::cout << "\t\t+Add first ToDo?<y/n> : ";
    while(true){
            std::cin >> choice;
            std::cin.ignore();
            if(choice == 'n'){
                break;
            }
            else if(choice == 'y'){
                if((*head_ref) == NULL){
                    firstNode = new list(); //allocating memory
                    (*head_ref) = firstNode;
                    std::cout << "\t\t" << countTopic <<".Topic: ";
                    std::cin.getline(firstNode->getToDo, MAX_TODO_SIZE);
                    firstNode->nextNode = NULL;
                }
                else{
                    lastNode = new list();
                    std::cout << "\t\t" << countTopic <<".Topic: ";
                    std::cin.getline(lastNode->getToDo, MAX_TODO_SIZE);
                    lastNode->nextNode = NULL;

                    firstNode->nextNode = lastNode;
                    firstNode = firstNode->nextNode;
                }            
            }
            else{
                std::cout << "\t\tWrong input! Enter Yes('y') Or No('n') only!\n"; 
                countTopic--;
            }
            std::cout << "\n";
            std::cout << "\t\t+Add more ToDo?<y/n> : ";
            countTopic++;
        }
}

void countToDo(list **head_ref){
    list *temp;
    int count = 1;
    temp = (*head_ref);
    std::cout << "\n\n\n\n";
    std::cout << "\t\tYour To-Dos:\n";
    std::cout << "\t\t-------------------------------\n";
    while(temp != NULL){
        std::cout << "\t\t"<< count <<"."<< temp->getToDo << std::endl;
        temp = temp->nextNode;
        count++;
    }
}

void deleteToDo(list **head_ref){
    system("cls");
    list *current = (*head_ref), *next;
    int selectOption;

    std::cout << "\n\n\n\n";
    std::cout << "\t\tDelete To-Dos:\n";
    std::cout << "\t\t------------------\n\n";
    std::cout << "\t\t1.Delete All         2.Delete any ToDo\n";
    std::cout << "\t\tSelect your option <1-2> : ";
    std::cin >> selectOption;
    std::cin.ignore();

    while(true){
        if(selectOption == 1){ //This section is to delete the whole list
            system("cls");
            if((*head_ref) == NULL){
                std::cout << "\n\n\n\n";
                std::cout << "\t\tThe list has no data to delete!\n\n\n\n";
                break;
            }
            else{
                while(current != NULL){
                next = current->nextNode;
                delete(current);
                current = next;
                }
                (*head_ref) = NULL;
                std::cout << "\n\n\n\n";
                std::cout << "\t\tThe list deleted successfully!\n\n\n\n";
                break;
            }
        }
        else if(selectOption == 2){ //This section is to delete the list items by nth position
            system("cls");
            if((*head_ref) == NULL){
                std::cout << "\n\n\n\n";
                std::cout << "\t\tThe list has no data to delete!\n\n\n\n";
                break;
            }
            else{
                displayList(head_ref);
                int pos;
                std::cout << "\n\n\n\n";
                std::cout << "\t\tEnter the serial number of ToDo that you want to delete: ";
                std::cin >> pos;
                if(pos == 1){
                    list *temp = (*head_ref);
                    (*head_ref) = temp->nextNode;
                    free(temp);
                    std::cout << "\t\tSuccessfully deleted! Check your To-Dos.\n";
                    break;
                }
                else if(pos > 1){
                    list *current = (*head_ref);
                    list *next = (*head_ref);
                    for(int i = 1; i <= pos-1; i++){
                        next = current;
                        current = current->nextNode;
                    }
                    next->nextNode = current->nextNode;
                    free(current);
                    current = NULL;
                    std::cout << "\t\tSuccessfully deleted! Check your To-Dos.\n";
                    break;
                }
            }
        }
    }
}

void updateToDo(list **head_ref){
    system("color 0F");
    system("cls");
    int step = 1;
    char choice;
    list *firstNode, *lastNode;
    std::cout << "\n\n\n\n";
    std::cout << "\t\tUpdate To-Dos:\n";
    std::cout << "\t\t----------------------\n\n";
    std::cout << "\t\t+Add new ToDo?<y/n> : ";
    while(true){
            std::cin >> choice;
            std::cin.ignore();
            if(choice == 'n'){
                break;
            }
            else if(choice == 'y'){
                if((*head_ref) == NULL){
                    std::cout <<"\n\t\tThe list is already empty! Please create a list first!\n";
                    break;
                }
                else{
                    firstNode = (*head_ref);
                    lastNode = new list();
                    std::cout << "\t\t" << step <<".Topic: ";
                    std::cin.getline(lastNode->getToDo, MAX_TODO_SIZE);
                    lastNode->nextNode = NULL;

                    while(firstNode->nextNode != NULL){
                        firstNode = firstNode->nextNode;
                    }
                    lastNode->nextNode = firstNode->nextNode;
                    firstNode->nextNode = lastNode;
                }            
            }
            else{
                std::cout << "\t\tWrong input! Enter Yes('y') Or No('n') only!\n"; 
                step--;
            }
            std::cout << "\t\t+Add more ToDo?<y/n> : ";
            step++;
        }
}

//---------------------------------------------The End----------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
