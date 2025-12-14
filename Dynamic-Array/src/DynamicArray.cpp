#include "DynamicArray.h"
#include <cstring>

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
   this->m_scaling_factor = scaling_factor;
   this->m_capacity = capacity;
   this->m_data = new int[capacity];
   this->m_length = 0;
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    this->m_scaling_factor = scaling_factor;
    this->m_length = length;
    this->m_capacity = length;
    this->m_data = new int[m_capacity];

    for (unsigned int i = 0; i < m_length; i++) {
        m_data[i] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::to_string() {
	// Initialize an empty string
    std::string str("");
	
	for (unsigned int i = 0; i < m_length; i++) {
        str += std::to_string(m_data[i]) + " ";
    }
    return str;
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;
    for (int i = 0; i < m_length; i++) {
        if (m_data[i] == value) {
            *index = i;
            found = true;
            break;
        }
    }
    return found;
}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;
    for (unsigned int i = m_length - 1; i >= 0; i--) {
        if(m_data[i] == value) {
            *index = i;
            found = true;
            break;
        }
    }
    
    return found;
}

void DynamicArray::append(int value) {
   if (m_length == m_capacity) {
    m_capacity = m_scaling_factor * m_capacity;
    int* data2 = new int[m_capacity];

    for (unsigned int i = 0; i < m_length; i++) {
        data2[i] = m_data[i];
    } 

    delete[] m_data;
    m_data = data2;
  
    }
    m_data[m_length] = value;
    m_length++;
   }


void DynamicArray::prepend(int value) {
    int* data2= nullptr;
     if (m_length == m_capacity) {
    m_capacity = m_scaling_factor * m_capacity;
    data2 = new int[m_capacity];
     }
     else {
        data2 = new int[m_capacity];
     }
     for (unsigned int i = m_length; i > 0; i--) {
            data2[i] = m_data[i-1];
     }
    delete[] m_data;
    m_data = data2;
    
    m_data[0] = value;
    m_length++;
}

void DynamicArray::remove_last() {
    if (m_length == 0) {
        return;
    }
    m_length--;
}

void DynamicArray::remove_first() {
    if (m_length == 0) {
        return;
    }
    
    for(unsigned int i = 0; i < m_length -1; i++) {
        m_data[i] = m_data[i + 1];
    }
    m_length--;
}

void DynamicArray::clear() {
    delete[] m_data;

    m_length = 0;
    m_capacity = 1;

    m_data = new int[m_capacity];
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
}
