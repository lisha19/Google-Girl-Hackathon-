int circuitt[SIZE][SIZE] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};


int outputs[SIZE] = {0, 1, 1, 0};
int obser_outputs[SIZE] = {0, 1, 0, 0};

int id_fault(int circuitt[][SIZE], int outputs[], int obser_outputs[]) {
   
    for (int node = 0; node <SIZE; node++) {
       
        int  pattern[SIZE] = {0};
        pattern[node] = 1;
        
     
        int output_response[SIZE] = {0};
        apply_test_pattern(circuit, test_pattern, output_response);

     
        int same = 1;
        for (int i = 0; i < SIZE; i++) {
            if (output_response[i] != obser_outputs[i]) {
                same= 0;
                break;
            }
        }

        if (same) {
        
            return node;
        }
    }


    return -1;
}

void apply_test_pattern(int circuitt[][SIZE], int pattern[], int output_response[]) {

    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            output_response[i] |=  pattern[j] & circuit[i][j];
        }
    }
}

int main() {

    int fault = id_fault(circuitt, outputs, obser_outputs);

    if (fault != -1) {
        printf("Fault %d\n", faulty_node);
    } else {
        printf("No fault.\n");
    }

    return 0;
}
