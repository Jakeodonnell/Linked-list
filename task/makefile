OBJ_SINGLE = bin/single_linked_list.o
OBJ_DOUBLE = bin/double_linked_list.o
OBJ_UNITY = bin/unity.o
OBJ_UNITY_SINGLE = bin/test_functions_single_linked_list.o
OBJ_UNITY_DOUBLE = bin/test_functions_double_linked_list.o
CC = gcc

build_unity_test_single: test/unity_test_single_linked_list.c $(OBJ_SINGLE) $(OBJ_UNITY) $(OBJ_UNITY_SINGLE)
	$(CC) test/unity_test_single_linked_list.c -o bin/unity_test_single_linked_list.exe -Lbin $(OBJ_SINGLE) $(OBJ_UNITY) $(OBJ_UNITY_SINGLE)

build_unity_test_double: test/unity_test_double_linked_list.c $(OBJ_DOUBLE) $(OBJ_UNITY) $(OBJ_UNITY_DOUBLE)
	$(CC) test/unity_test_double_linked_list.c -o bin/unity_test_double_linked_list.exe -Lbin $(OBJ_DOUBLE) $(OBJ_UNITY) $(OBJ_UNITY_DOUBLE)

bin/single_linked_list.o: src/single_linked_list.c src/single_linked_list.h
	$(CC) -c src/single_linked_list.c -o bin/single_linked_list.o 

bin/double_linked_list.o: src/double_linked_list.c src/double_linked_list.h
	$(CC) -c src/double_linked_list.c -o bin/double_linked_list.o 

bin/test_functions_single_linked_list.o: test/test_functions_single_linked_list.c test/test_functions_single_linked_list.h
	$(CC) -c test/test_functions_single_linked_list.c -o bin/test_functions_single_linked_list.o 

bin/test_functions_double_linked_list.o: test/test_functions_double_linked_list.c test/test_functions_double_linked_list.h
	$(CC) -c test/test_functions_double_linked_list.c -o bin/test_functions_double_linked_list.o 

bin/unity.o: unity/unity.c unity/unity.h unity/unity_internals.h
	$(CC) -c unity/unity.c -o bin/unity.o 

clean:
	rm -f bin/*

