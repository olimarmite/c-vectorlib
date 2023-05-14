
+-------------+
| C-VECTORLIB |
+-------------+

The vector lib is a simple and easy to use c library adding c++ like vectors.

exemple:

{
	t_vector	my_vector;
	int		my_object;
	
	my_object = 10;

	my_vector = vector_create(&my_vector, sizeof(int));	//Allocate  and initialised all the memory used by the vector, returns a pointer to itself.
								//The parameter is the size of the type,
								//that the vector is going to use.

	vector_add(&vector, &my_object);	//Add an object at the end of the vector and returns it.
						//(note that the growth factor of the vector is x1.5)
	vector_get(&vector, 0u);		//Returns an object at a certain index in the vector.
	vector_pop(&vector, &my_object);	//Remove the object at the end of the vector and returns it.
	vector_destroy(&vector);		//Free all the memory used by the vector.
}
