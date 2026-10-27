#pragma once

#include "IntegerArray.hpp"
#include "FloatArray.hpp"
#include "MemoryAllocator.hpp"

namespace pankey{

    namespace Support{

        namespace Math{

            struct Tensor{

                IntegerArray m_shape;
                IntegerArray m_strides;
                FloatArray m_data;

                Tensor() = default;

                Tensor(const IntegerArray& a_shape){
                    create(a_shape);
                }

                bool create(const IntegerArray& a_shape){
                    if(a_shape.isEmpty()){
                        clear();
                        return false;
                    }

                    int i_element_count = 1;

                    for(int i = 0; i < a_shape.length(); ++i){
                        if(a_shape.getFast(i) <= 0){
                            clear();
                            return false;
                        }
                        i_element_count *= a_shape.getFast(i);
                    }

                    m_shape.createArray(a_shape.length());
                    m_strides.createArray(a_shape.length());
                    m_data.createArray(i_element_count);

                    for(int i = 0; i < a_shape.length(); ++i){
                        m_shape.setFast(i, a_shape.getFast(i));
                    }
                    m_shape.setLength(a_shape.length());

                    m_strides.setFast(a_shape.length() - 1, 1);
                    for(int i = a_shape.length() - 1; i > 0; --i){
                        m_strides.setFast(i - 1, m_strides.getFast(i) * m_shape.getFast(i));
                    }
                    m_strides.setLength(a_shape.length());

                    for(int i = 0; i < i_element_count; ++i){
                        m_data.setFast(i, 0.0f);
                    }
                    m_data.setLength(i_element_count);
                    return true;
                }

                void clear(){
                    m_shape.clear();
                    m_strides.clear();
                    m_data.clear();
                }

                int rank() const{
                    return m_shape.length();
                }

                int size() const{
                    return m_data.length();
                }

                bool empty() const{
                    return m_data.isEmpty();
                }

                const IntegerArray& shape() const{
                    return m_shape;
                }

                bool set(const IntegerArray& a_indices, float a_value){
                    int i_offset = 0;
                    if(!offset(a_indices, i_offset)){
                        return false;
                    }
                    m_data.setFast(i_offset, a_value);
                    return true;
                }

                bool get(const IntegerArray& a_indices, float& a_value) const{
                    int i_offset = 0;
                    if(!offset(a_indices, i_offset)){
                        return false;
                    }
                    a_value = m_data.getFast(i_offset);
                    return true;
                }

                float get(const IntegerArray& a_indices) const{
                    int i_offset = 0;
                    if(!offset(a_indices, i_offset)){
                        return 0.0f;
                    }
                    return m_data.getFast(i_offset);
                }

                const FloatArray& values() const{
                    return m_data;
                }

            private:
                bool offset(const IntegerArray& a_indices, int& a_offset) const{
                    if(a_indices.length() != m_shape.length()){
                        return false;
                    }

                    a_offset = 0;
                    for(int i = 0; i < a_indices.length(); ++i){
                        if(a_indices.getFast(i) < 0 || a_indices.getFast(i) >= m_shape.getFast(i)){
                            return false;
                        }
                        a_offset += a_indices.getFast(i) * m_strides.getFast(i);
                    }
                    return true;
                }
            };

        }

    }

}