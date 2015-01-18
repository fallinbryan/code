/*
 * TypeBase.h
 *
 *  Created on: 17.01.2015
 *      Author: aschaeffer
 */

#ifndef SRC_ENGINE_ENTITY_TYPEBASE_H_
#define SRC_ENGINE_ENTITY_TYPEBASE_H_

#include "EntitySystemBase.h"
#include "AttributeBase.h"

#include "EntityAttribute.h"
#include "EntityFunction.h"

class TypeBase : public AttributeBase
{
    public:
        TypeBase(std::string name, bool persist, bool synchronize);
        virtual ~TypeBase();

        std::string GetUuid() { return uuid; };
        std::string GetName() { return name; };
        bool IsPersisting() { return persist; };
        bool IsSynchronizing() { return synchronize; };

        /*
        void Execute(std::string key) {
            if (attributes[key]->type == ENTATTR_FUNCTION) {
                attributes[key]->functionVal->Execute(this);
            }
        }
        */

    protected:

        /**
         * The unique identifier of this type.
         */
        std::string uuid;

        /**
         * The name of the type.
         */
        std::string name;

        /**
         * Instances of this type should be persisted.
         */
        bool persist;

        /**
         * Instances of this type should be synchronized.
         */
        bool synchronize;

        // Include the default reference counting implementation.
        IMPLEMENT_REFCOUNTING(TypeBase);
};

template <class T>
class TypeRefPtr : public CefRefPtr<T> {
    public:
        typedef CefRefPtr<T> parent;

        TypeRefPtr() : parent() {
        }

        TypeRefPtr(T* p) : parent(p) {
        }

        TypeRefPtr(const CefRefPtr<T>& r) : parent(r) {
        }

        template <typename U>
        TypeRefPtr(const CefRefPtr<U>& r) : parent(r) {
        }

        AttributeRefPtr operator[](std::string key) const
        {
            AttributeRefPtr attribute = this->get()->GetAttribute(key);
            attribute->name = key;
            return attribute;
        };

};

#endif /* SRC_ENGINE_ENTITY_TYPEBASE_H_ */
