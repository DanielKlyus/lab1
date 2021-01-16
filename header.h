#ifndef TRITSET_TRITSET_H
#define TRITSET_TRITSET_H
#include <iostream>
#include <vector>
#include <initializer_list>

typedef unsigned int uint;
using namespace std;

enum class Trit
{
    Unknown, True, False
};

class TritSetTrit
{
	private:
	class TritSet &set;

    uint nmb;
    uint &pointer;
    uint shift;
    
	public:
    TritSetTrit(TritSet &, uint, uint &, uint);

    TritSetTrit &operator=(const Trit &);

    bool operator==(Trit);

    operator Trit();
};

class TritSet
{
	private:
    uint true_amount;
    uint false_amount;
    uint unknown_amount;
    uint lastImportantTrit;
    bool isChecked;
    const uint TRITS_IN_UINT = sizeof(uint) * 4;
    uint size;
    vector<uint> trits;
	
	public:
    class iterator
	{
		private:
        TritSet *parent;
        uint index;
		
		public:
        iterator(TritSet *, uint);

        iterator &operator++();

        bool operator!=(const iterator &);
        Trit operator*();
    };

    iterator begin();
    iterator end();

    friend class TritSetTrit;
    TritSet &operator=(const TritSet &);
    TritSet(initializer_list<Trit>);
    TritSet operator&(const TritSet &) const;
    TritSet operator|(const TritSet &) const;
    TritSet operator!();
    void check() const;
    void shrink();
    size_t cardinality(Trit) const;
    size_t length() const;
    void trim(size_t);
    explicit TritSet(uint);
    uint capacity() const;
    Trit operator[](uint) const;
    TritSetTrit operator[](uint);
};

ostream &operator<<(ostream &, Trit &);
ostream &operator<<(ostream &, TritSet &);

int testes();
#endif
