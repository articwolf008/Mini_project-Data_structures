#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    int severity;
} Patient;

Patient heap[MAX];
int size = 0;

// Swap
void swap(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].severity < heap[index].severity) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify Down
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].severity > heap[largest].severity)
        largest = left;

    if (right < size && heap[right].severity > heap[largest].severity)
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// Add Patient
void addPatient() {
    if (size >= MAX) {
        printf(”Queue is full!\n”);
        return;
    }

    Patient p;
    printf(”Enter name: “);
    scanf(”%s”, p.name);
    printf(”Enter age: “);
    scanf(”%d”, &p.age);
    printf(”Enter severity (1-10): “);
    scanf(”%d”, &p.severity);

    heap[size] = p;
    heapifyUp(size);
    size++;

    printf(”Patient added successfully!\n”);
}

// Treat Patient
void treatPatient() {
    if (size == 0) {
        printf(”No patients in queue!\n”);
        return;
    }

    printf(”Treating patient: %s (Severity: %d)\n”, heap[0].name, heap[0].severity);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Display Patients
void displayPatients() {
    if (size == 0) {
        printf(”No patients waiting.\n”);
        return;
    }

    printf(”\nWaiting List:\n”);
    for (int i = 0; i < size; i++) {
        printf(”%s | Age: %d | Severity: %d\n”, heap[i].name, heap[i].age, heap[i].severity);
    }
}

int main() {
    int choice;

    while (1) {
        printf(”\n------ Hospital Emergency System ------\n”);
        printf(”1. Add Patient\n”);
        printf(”2. Treat Patient\n”);
        printf(”3. Display Waiting List\n”);
        printf(”4. Exit\n”);
        printf(”Enter choice: “);
        scanf(”%d”, &choice);

        switch (choice) {
            case 1: 
            addPatient(); 
            break;
            
            case 2: 
            treatPatient(); 
            break;
            
            case 3: 
            displayPatients(); 
            break;
            
            case 4: 
            exit(0);
            
            default: 
            		printf(”Invalid choice!\n”);
        }
    }

    return 0;
}
