// Librerias 
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

// Namespaces
using namespace std;

// Crear clases contenidas
struct TPunto
{
    
    int x;
    int y;
};

// Creamos la clase contenedor
class CMapa
{
    string nombreArchivo;
    string ciudad;
    vector<TPunto> listaPuntos; // Relacion de 1 a muchos

public:

    // Declaracion de constructores
    CMapa ()
    {
        ciudad = "Lima";
        nombreArchivo = "datos.txt";
    }
    
    CMapa (string ciudad, string nombreArchivo)
    {
        this->ciudad = ciudad;
        this->nombreArchivo = nombreArchivo;
    }
    
    // Metodos de Procesamientos
    void agregarPunto(int x, int y)  //A
    {
        listaPuntos.push_back({x,y});
        grabarArchivo();
    }
    
    void listarPuntos() //A
    {
        for (auto punto: listaPuntos)
            cout << "Punto  x, y = (" << punto.x << ", " << punto.y << ")" << endl;
    }
    
    void eliminarPuntoPorX(int x)
    {
        for (int i = listaPuntos.size() - 1; i >= 0; i--)
        {
            if (listaPuntos[i].x == x)
                listaPuntos.erase(listaPuntos.begin() + i);
        }
        grabarArchivo();
    }
     void eliminarPuntoPorY(int y)
     {
       for (int i = listaPuntos.size() - 1; i >= 0; i--)
        {
            if (listaPuntos[i].y == y)
                listaPuntos.erase(listaPuntos.begin() + i);
        }
        grabarArchivo();  
     }
    
    void grabarArchivo()
    {
        // Creando el archivo
        ofstream archivo(nombreArchivo);
        archivo << "posX,    posY,      lugar,   estado" << endl;
        for (auto punto: listaPuntos)
            archivo << punto.x << ", " << punto.y << endl;
        archivo.close();
    }
    void LpM()  //Listar los puntos ubicados a menos de 10 metros.   //A
   {
        int x;
        int y;
        cout<<"Ingrese el punto coordenada x : ";
        cin>>x;
        cout<<"Ingrese el punto coordenada y : ";
        cin>>y;
        
        bool vi = false; 
        for (auto punto: listaPuntos) {
            if( punto.x == x && punto.y == y){
                vi = true;
            }
        }
        
        if(vi == true) {
            for(auto punto: listaPuntos){
                float distancia = sqrt(pow(x-punto.x,2)+pow(y-punto.y,2));
                if(distancia <= 10){
                    cout<<"Punto "<<punto.x<<" "<<punto.y<<endl;
                }
            }
        } else {
            cout<<"El punto no esta en la lista de puntos";
        }
        
   }

     void DpEcP() //Calcular la distancia promedio entre cada punto. // A
   {
       
        float promedio;
        float contadorDeCaminos=0;
        float suma;
        
        for(int i=0; i<listaPuntos.size();i++)
        {
            for(int j=i+1;j<listaPuntos.size();j++)
            {
                 float distancia = sqrt(((listaPuntos[i].x)-(listaPuntos[j].x))*((listaPuntos[i].x)-(listaPuntos[j].x)) + ((listaPuntos[i].y)-(listaPuntos[j].y))*((listaPuntos[i].y)-(listaPuntos[j].y)));
                
                 suma+= distancia;
                
                 contadorDeCaminos++;
            }
        }
        
        promedio = suma/contadorDeCaminos;
        
        cout << "promedio: "<<promedio << endl;
   }
    void DPmL() // Determinar la distancia entre los puntos más lejanos.
    
    {
    	float maslejana = -1;
        for(int i=0; i<listaPuntos.size();i++)
     {
            for(int j=i+1;j<listaPuntos.size();j++)
             
            {
          float distancia=  sqrt(pow(listaPuntos[i].y-listaPuntos[j].y,2)+pow(listaPuntos[i].x-listaPuntos[j].x,2));
            
                if(distancia>maslejana){
                    maslejana = distancia;
                }
                
            }
      
            }
      cout<<"La distancia mas larga entre los puntos "<<maslejana<<endl;   
    }

    void dMceP()  // Determinar la distancia más corta entre los puntos.

    {
    	float mascorta = 99999999;
        for(int i=0; i<listaPuntos.size();i++)
     {
            for(int j=i+1;j<listaPuntos.size();j++)
             
            {
          float distancia=  sqrt(((listaPuntos[i].x)-(listaPuntos[j].x))*((listaPuntos[i].x)-(listaPuntos[j].x)) + ((listaPuntos[i].y)-(listaPuntos[j].y))*((listaPuntos[i].y)-(listaPuntos[j].y)));
            
                if(distancia<mascorta){
                    mascorta = distancia;
                }
                
            }
      
            }
      cout<<"La distancia mas corta entre los puntos "<<mascorta<<endl;      
     }
    void pendiente() // determinar la pendiente entre dos puntos  //A
    {
        float x1;
        float y1;
        float x2;
        float y2;
        
        cout<<"Ingresa la coordenada del Punto 1 en el eje x : ";
        cin>>x1;
        cout<<"Ingresa la coordenada del Punto 1 en el eje y : ";
        cin>>y1;
        
        cout<<"Ingresa la coordenada del Punto 2 en el eje x : ";
        cin>>x2;
        cout<<"Ingresa la coordenada del Punto 2 en el eje y : ";
        cin>>y2;
        
        if(y1==y2){
            cout<<"No podemos calcular la pendiente de ese punto";
        } else {
        
            float pendiente = (x2-x1)/(y2-y1);
            cout<<"La pendiente entre estos dos puntos es "<<pendiente;
        }
    }
    void tiempo()
    {
        float x1;
        float y1;
        float x2;
        float y2;
        
        cout<<"Ingresa la coordenada del Punto 1 en el eje x : ";
        cin>>x1;
        cout<<"Ingresa la coordenada del Punto 1 en el eje y : ";
        cin>>y1;
        
        cout<<"Ingresa la coordenada del Punto 2 en el eje x : ";
        cin>>x2;
        cout<<"Ingresa la coordenada del Punto 2 en el eje y : ";
        cin>>y2;
       
       float velocidad; 
       cout<<"Ingrese la velocidad : ";
       cin>>velocidad;
       
       float distancia=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
       float tiempo = distancia/velocidad;
       
       cout<<"El tiempo que toma recorrer la distancia entre el Punto 1 ("<<x1<<","<<y1<<") y el Punto 2 ("<<x2<<","<<y2<<") es "<<tiempo<<endl;
      
    }
    
};

// Metodo menu
int menu()
{
    int opcion = 0;
    
    do
    {
        system ("clear");
        cout << "MENU" << endl;
        cout << string(4, '~') << endl << endl;
        
        cout << "1. Ingresar Puntos" << endl;
        cout << "2. Listar Puntos" << endl;
        cout << "3. Eliminar por Posicion X" << endl;
        cout << "4. Eliminar por Posicion Y" << endl;
        cout << "5. Listar los puntos ubicados a menos de 10 metros" << endl;
        cout << "6. Calcular la distancia promedio entre cada punto" << endl;
        cout << "7.  Determinar la distancia entre los puntos más lejanos" << endl;
        cout << "8. Determinar la distancia más corta entre los puntos" << endl;
        cout << "9. calcular la pendiente de la recta de dos puntos"  << endl;
        cout << "10. calcular el tiempo que demora en recorrer la recta entre dos puntos" << endl;
        
        cout << "0. Para salir" << endl << endl;
        cout << "Opcion : ";
        cin >> opcion;
    }
    while (opcion > 10 || opcion < 0);
    
    
    return opcion;
}

// Programa Principal
int main ()
{
    
    CMapa mapa;         // Mapa de Lima
   
    int opcion = 0;
    do
    {
        opcion = menu(); // Opcion del menu
        int x, y;
        
        // Creamos un switch de opciones
        switch(opcion)
        {
            case 1:     // Insertar Puntos 
                system("clear");
                cout << "Ingrese el valor de X: "; cin >> x;
                cout << "Ingrese el valor de Y: "; cin >> y;
                mapa.agregarPunto(x, y);
                break;
                
            case 2:     // Listar Puntos
                system("clear");
                mapa.listarPuntos();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
                
            case 3:     // Eliminar Punto 
                system("clear");
                cout << "Ingrese el X del punto a borrar : "; cin >> x;
                mapa.eliminarPuntoPorX(x);
                break;
                
           case 4:     
                system("clear");
                cout << "Ingrese el Y del punto a borrar : "; cin >> y;
                mapa.eliminarPuntoPorY(y);
                break;
                
            case 5:   //Listar los puntos ubicados a menos de 10 metros.
            system("clear");
            mapa.LpM();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
                
            case 6://Calcular la distancia promedio entre cada punto
            system("clear");
            mapa.DpEcP();
            
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
            break;
            
            case 7:// Determinar la distancia entre los puntos más lejanos
            system("clear");
            mapa.DPmL();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.get();
            break;
            
            case 8:  //"8. Determinar la distancia más corta entre los puntos
            system("clear");
            mapa.dMceP();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.get();
            
            break;
            
            case 9: //calcular la pendiente de la recta de dos puntos
            system("clear");
            
             mapa.pendiente();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.get();
             break;
            
            
            case 10: //tiempo que se demora en recorrer de un punto a otro ingresando una velocidad
             system("clear");
             
             mapa.tiempo();
             cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.get();
            
            break;
            
             
            
        }
        
    }
    while (opcion != 0);
    
    return 0;
}