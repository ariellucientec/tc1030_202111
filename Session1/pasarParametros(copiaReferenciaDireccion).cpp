/*
    Tema: Paso de parámetros

    a) por valor - se copias los parámetros (desventaja: hay variables duplicadas en memoria)
    b) por referencia - se hace referencia a los valores de datos originales y NO se copian en memoria (parámetros con Ampersand & )
    c) por dirección - se hace referencia a los valores de datos originales utilizando apuntadores (NO hay copias de datos en memoria)

*/

// Paso de parámetros por valor (copia)
int add(int num1, int num2)
{
    return num1+num2;
}


// Paso de parámetros por referencia (los parámetros referencian a los valores originales)
// el único cambio, respecto a pasar por valor es Agregar el ampersand & a cada parámetro
int multiply(int &num1, int &num2)
{
    return num1*num2;
}


// Paso de parámetros por dirección (los parámetros son apuntadores que apuntan a los valores originales)
// en el código se cambia la declaración de los parámetros (por apuntadores) y en el cuerpo de la función se dereferencían los valores para poder usarlos
int substract(int *num1, int *num2)
{
    return *num1 - *num2;  //como num1 y num2 son apuntadores, es necesario dereferenciarlos para obtener su valor
}

int main()
{
    int n1=10, n2=33;

    add(n1, n2);

    multiply(n1, n2);

    // Dado que los parámetros de substract son apuntadores, entonces es necesario pasar direcciones
    // para obtener la dirección de n1 y n2 se utiliza el operador &
    substract(&n1, &n2);


}