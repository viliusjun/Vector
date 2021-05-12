dataType elementAt(dataType *vector, int size, int index, int *errorCode);

// Function that return the value of an element at the specific index of the vector
// errorCode = 1 if index is smaller than zero, or bigger or equal than the size of the vector
dataType elementAt(dataType *vector, int size, int index, int *errorCode){
    if (index < 0 || index >= size){
        *errorCode = 1;
        return *errorCode;
    }

    dataType element = *(vector + index);

    return element;
}


printf("Press 5 if you want to get the value of an element at a specific index of the vector\n");

else if (flag == 5){
            if (created == 0){
                printf("\nThe vector is not created. Create the vector first\n");
                flag = 0;
            }
            else {
                printf("\nInput the index of the element you want to get\n");
                scanf("%d", &index);

                dataType currentElement = elementAt(vector, size, index, &errorCode);
                if (errorCode == 1){
                    printf("That is not a valid index. The index cannot be smaller than zero, or bigger or equal than the size of the vector\n");
                }
                errorCode = 0;
                flag = 0;
            }
        }