#include <iostream>
#include <new>
#include <stdexcept>



using namespace std;




template<class T>
class Array
{
	private:
		T* dato_;
		int size_;
		int i;
	public:
		Array();
		Array(int size);
		~Array();
		void set(T dato, int pos);
		T get(int pos);
		int get_size();
		void suma(Array<T>& arr, Array<T>& arr2);
		void resta(Array<T>& arr, Array<T>& arr2);
		void multiplicacion(Array<T>& arr, Array<T>& arr2);
		void division(Array<T>& arr, Array<T>& arr2);
		int get_i(void);
		void busqueda(T dato);
		void resize(int new_size);
		bool empty();
		bool full();
		void clear();
		void imprimir();
		T& operator[](int i); 
		void push_back(T dato);
		
};

template<class T>
Array<T>::Array():
size_(10),
i(0)
{

try
{
	dato_ = new T [size_];
	
	for(int i=0;i<size_;i++)
	{
		dato_[i]=0;
	}
}
catch(std::bad_alloc& ba)
{
	cout << "Fallo en la reserva de memoria " << ba.what() << endl;
}
	
}



template<class T>
Array<T>::Array(int size):
	size_(size),
	i(0)
{

try
{
	dato_ = new T [size_];
	
	for(int i=0;i<size_;i++)
	{
		dato_[i]=0;
	}
}
catch(bad_alloc& ba)
{
	cout << "Fallo en la reserva de memoria " << ba.what() << endl;
}
	
}

template<class T>
Array<T>::~Array()
{
	if(dato_!=NULL)
	{
		delete [] dato_;
		size_=0;
		i=0;
	}
}

template<class T>
void Array<T>::set(T dato, int pos)
{
	if(pos <= get_size()-1)
	{
		dato_[pos]=dato;
		i=pos;
	}
	
}

template<class T>
T Array<T>::get(int pos)
{
	return dato_[pos];
}

template<class T>
void Array<T>::push_back(T dato)
{
	resize(get_size()+1);
	set(dato,get_size()-1);
}

template<class T>
int Array<T>::get_size()
{
	return size_;
}

template<class T>
void Array<T>::resize(int new_size)
{

try
{
	int old_size = size_;
	T* aux = NULL;

	size_ = new_size;
	
	aux = new T [size_];
	
	aux = dato_;
	dato_ = new T [size_];
	
	for(int i=0;i<old_size;i++)
	{
		dato_[i]=aux[i];
	}
}
catch(const length_error& le)
{
	cerr << "Fallo en el redimensionado " << le.what() << endl;
}
		
	
}

template<class T>
void Array<T>::imprimir()
{
	for(int i=0; i<get_size();i++)
	{
		cout << get(i) << " ";
	}
	cout << endl;
}

template<class T>
void Array<T>::busqueda(T dato)
{
	
	bool encontrado = false;
	int pos=0;
	int j=0;
	
	
	
	cout << endl << "El valor " << dato << " esta en la posicion/posiciones: ";	
	for(int i=0; i<get_size(); i++)
	{
		if(dato_[i]==dato)
		{
			encontrado=true;

			cout <<  i+1 << " ";; 
			
		}
	}
	cout << endl;
	
	
	if(!encontrado)
	cout << endl << "No existe dentro del vector" << endl;
	
}

template<class T>
void Array<T>::suma(Array<T>& arr, Array<T>& arr2)
{
	if(arr2.get_size()==arr.get_size())
	{
		for(int i=0; i<get_size(); i++)
		{
			set(arr.get(i)+arr2.get(i),i);
		}
	}
	
}

template<class T>
void Array<T>::resta(Array<T>& arr, Array<T>& arr2)
{
	if(arr.get_size()==arr2.get_size())
	{
		for(int i=0; i<arr.get_size(); i++)
		{
			set(arr.get(i)-arr2.get(i),i);
		}
	}
	
}

template<class T>
void Array<T>::multiplicacion(Array<T>& arr, Array<T>& arr2)
{
	
	if(arr2.get_size()==arr.get_size())
	{
	
		for(int i=0; i<arr.get_size(); i++)
		{
			set(arr.get(i)*arr2.get(i),i);
		}
	
	}
	
	
}

template<class T>
void Array<T>::division(Array<T>& arr, Array<T>& arr2)
{
	
	if(arr2.get_size()==arr.get_size())
	{
		for(int i=0; i<arr.get_size(); i++)
		{
						
			try
			{	
				if(arr2.get(i)!=0)
				set(arr.get(i)/arr2.get(i),i);
				else
				throw 0;
			}
			catch(int e)
			{
				cout << "No se puede dividir por " << e << endl;
			}
			
			
			
			
		}
	}
	
	
}

template<class T>
T& Array<T>::operator[](int i)
{ 
	try
	{
		if(i<get_size())
		return dato_[i];
		else
		throw 2;
	}
	catch(int e)
	{
		cout << "Error, el tamaño del vector es menor que la posicion requerida\n";
		return dato_[get_size()-1];
	}
	

}

template<class T>
int Array<T>::get_i()
{
	return i;
}

template<class T>
bool Array<T>::empty()
{
	return (dato_==NULL);
}

template<class T>
bool Array<T>::full()
{
	return (get_i()==get_size());
}

template<class T>
void Array<T>::clear()
{
	for(int i=0; i<get_size();i++)
	{
		set(0,i);
	}
}

