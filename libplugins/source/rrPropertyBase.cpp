#pragma hdrstop
#include <iostream>
#include <iomanip>
#include "rrStringUtils.h"
#include "rrPropertyBase.h"
//---------------------------------------------------------------------------

namespace rrp
{
using namespace std;
using namespace rr;

PropertyBase::PropertyBase(const string& type, const string& name, const string& hint, const string& descr, const string& alias, bool readOnly)
:
mName(name),
mHint(hint),
mDescription(descr),
mType(type),
mAlias(alias),
mReadOnly(readOnly)
{}

PropertyBase::~PropertyBase()
{}

PropertyBase::PropertyBase(const PropertyBase& pp)
{
    //We could assert here, assigning incompatible types
    mName           = pp.mName;
    mType           = pp.mType;
    mHint           = pp.mHint;
    mDescription    = pp.mDescription;
    mReadOnly       = pp.mReadOnly;
    mAlias          = pp.mAlias;
}

PropertyBase& PropertyBase::operator=(const PropertyBase& rhs)
{
    if((this) == &rhs)
    {
        return *(this);
    }

    mName = rhs.mName;
    mType = rhs.mType;
    mHint = rhs.mHint;
    return *(this);
}

string PropertyBase::getType() const
{
    return mType;
}

string PropertyBase::getName() const
{
    return mName;
}

string PropertyBase::getAlias() const
{
    return mAlias;
}


string PropertyBase::getHint() const
{
    return mHint;
}

bool PropertyBase::isReadOnly() const
{
    return mReadOnly;
}

string PropertyBase::getDescription() const
{
    return mDescription;
}

void PropertyBase::setDescription(const string& descr)
{
    mDescription = descr;
}

void PropertyBase::setHint(const string& hint)
{
    mHint = hint;
}

void* PropertyBase::getValueHandle()
{
    return NULL;
}

string PropertyBase::getValueAsString() const
{
    stringstream val;
    val<<"The type:"<<getType()<<" do not have a string representation.";
    return val.str();
}

ostream& operator<<(ostream& stream, const PropertyBase& outMe)
{
    stream<<outMe.asString();
    return stream;
}

string PropertyBase::asString() const
{
    stringstream val;
    val<<setfill('.');
    val<<setw(20)<<left<<"Name: "         << mName<<endl;
    val<<setw(20)<<left<<"Type: "         << getType()<<endl;
    val<<setw(20)<<left<<"Value: "        << getValueAsString()<<endl;
    val<<setw(20)<<left<<"Hint: "         << mHint<<endl;
    val<<setw(20)<<left<<"Description: "  << mDescription<<endl;
    val<<setw(20)<<left<<"Alias: "        << mAlias<<endl;
    val<<setw(20)<<left<<"ReadOnly: "     << toString(mReadOnly)<<endl;
    return val.str();
}



}
