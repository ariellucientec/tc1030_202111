/* 
        CLASES AMIGAS

    Se necesita una forma en la que una clase tenga acceso a los atributos y métodos PRIVADOS o PROTEGIDOS
    de otra clase. La manera de hacerlo es haciendo clases amigas
    
*/
class classA
{
private:
    int privateVal;
protected:
    int protectedVal;


public:
    friend class classB;
};

class classB
{
    classA* c;
public:   
    void setPrivateVal()
    {
        c->privateVal = 10;
        c->protectedVal = 20;
    }
};

int main()
{
    classB b;
    b.setPrivateVal(); 
}

