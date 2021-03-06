/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/
/*
*Dense Integer Polynomials
*/
//Schauen was hier überhaupt sinn macht
#include "config.h"
#include <misc/auxiliary.h>

#ifdef HAVE_FACTORY
#include <factory/factory.h>
#endif

#include <string.h>
#include <omalloc/omalloc.h>
#include <coeffs/coeffs.h>
#include <reporter/reporter.h>
#include <coeffs/numbers.h>
#include <coeffs/longrat.h>
#include <coeffs/modulop.h>
#include <coeffs/mpr_complex.h>
#include <misc/mylimits.h>
#include <coeffs/OPAEQ.h>
#include <coeffs/AEQ.h>





// DEFINITION DER FUNKTIONEN

number  nAEQAdd(number a, number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    Q_poly *res=new Q_poly;
    res->Q_poly_set(*f);
    res->Q_poly_add_to(*g);
    return (number) res;
}

number  nAEQMult(number a, number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    Q_poly *res=new Q_poly;
    res->Q_poly_set(*f);
    res->Q_poly_mult_n_to(*g);
    return (number) res;
}

number  nAEQSub(number a, number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    Q_poly *res=new Q_poly;
    res->Q_poly_set(*f);
    res->Q_poly_sub_to(*g);
    return (number) res;
}


number  nAEQDiv(number a, number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    Q_poly *res=new Q_poly;
    Q_poly *s=new Q_poly;
    res->Q_poly_set(*f);
    res->Q_poly_div_to(*res,*s,*g);
    return (number) res;
}


number  nAEQIntDiv(number a, number b,const coeffs r)
{

    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    mpz_t* i= reinterpret_cast<mpz_t*> (b);
    Q_poly *res=new Q_poly;
    res->Q_poly_set(*f);
    res->Q_poly_scalar_div_to(*i);
    return (number) res;
}

number  nAEQIntMod(number a, number b,const coeffs r)
{
    return a;
}

number  nAEQExactDiv(number a, number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    Q_poly *res=new Q_poly;
    Q_poly *s=new Q_poly;
    res->Q_poly_set(*f);
    res->Q_poly_div_to(*res,*s,*g);
    return (number) res;
}



number nAEQInit(long i, const coeffs r)
{
    number res = (number) i;
    return res;
}

number nAEQInitMPZ(mpz_t m, const coeffs r)
{
    number res= (number) m;
    return res;
}

int nAEQSize (number a,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    return f->deg;
}

int nAEQInt(number &a,const coeffs r)
{
    return 1;
}


number nAEQMPZ(number a,const coeffs r)
{
    return a;
}


number nAEQNeg(number c, const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (c);
    Q_poly *res=new Q_poly;
    res->Q_poly_set(*f);
    res->Q_poly_neg();
    return (number) res;
}

number nAEQCopy(number c, const coeffs r)
{
    return (number) c;
}

number nAEQRePart(number c, const coeffs r)
{
    return (number) c;
}

number nAEQImPart(number c, const coeffs r)
{
    return (number) c;
}

void    nAEQWriteLong   (number &a, const coeffs r)
{
    return;
}

void    nAEQWriteShort  (number &a, const coeffs r)
{
    return ;
}


const char *  nAEQRead  (const char *s, number *a,const coeffs r)
{
    return "";
}

number nAEQNormalize    (number a,number b,const coeffs r) // ?
{
    return a;
}

BOOLEAN nAEQGreater     (number a, number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    if (f->deg > g->deg) {return FALSE;}
    else {return TRUE;}
}

BOOLEAN nAEQEqual     (number a, number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    if (f->is_equal(*g) == 1) {return FALSE;}
    else {return TRUE;}
}

BOOLEAN nAEQIsZero      (number a,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    if (f->is_zero() == 1) {return FALSE;}
    else {return TRUE;}
}

BOOLEAN nAEQIsOne      (number a,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    if (f->is_one() == 1) {return FALSE;}
    else {return TRUE;}
}

BOOLEAN nAEQIsMOne      (number a,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    if (f->is_one() == 1) {return FALSE;}
    else {return TRUE;}
}

BOOLEAN nAEQGreaterZero     (number a, const coeffs r)
{
    if (nAEQIsZero(a,r) == FALSE) { return TRUE; }
    else { return FALSE; }
}

void    nAEQPower       (number a, int i, number * result,const coeffs r)
{
    return;
}

number nAEQGetDenom      (number &a, const coeffs r)
{
    return (number) 1;
}

number nAEQGetNumerator      (number &a, const coeffs r)
{
    return a;
}

number nAEQGcd           (number a,number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    Q_poly *res=new Q_poly;
    res->Q_poly_gcd(*f,*g);
    return (number) res;
}

number nAEQLcm          (number a,number b,const coeffs r)
{
    Q_poly* f=reinterpret_cast<Q_poly*> (a);
    Q_poly* g=reinterpret_cast<Q_poly*> (b);
    Q_poly *gcd=new Q_poly;
    Q_poly *res=new Q_poly;
    Q_poly *s=new Q_poly;
    gcd->Q_poly_gcd(*f,*g);
    res->Q_poly_mult_n(*f,*g);
    res->Q_poly_div_to(*res,*s,*gcd);
    return (number) res;
}

void    nAEQDelete       (number *a, const coeffs r)
{
    return;
}

/*
number    nAEQSetMap        (number a, const coeffs r)
{
        return a;
}
*/
char*    nAEQName       (number a, const coeffs r)
{
    char* c=new char;
    *c='c';

    return c;
}

void    nAEQInpMult       (number &a, number b,const coeffs r)
{
    return ;
}

void    nAEQCoeffWrite   (const coeffs r, BOOLEAN details)
{
    return;
}

BOOLEAN nAEQClearContent  (number a,const coeffs r)
{
    return FALSE;
}

BOOLEAN nAEQClearDenominators  (number a,const coeffs r)
{
    return FALSE;
}



//INITIALISIERUNG FÜR SINGULAR


BOOLEAN n_QAEInitChar(coeffs r,void *p) // vlt noch void* p hin
{



    r->ch=0;
    r->cfKillChar=NULL;
    r->nCoeffIsEqual=ndCoeffIsEqual;
    r->cfMult  = nAEQMult;
    r->cfSub   = nAEQSub;
    r->cfAdd   = nAEQAdd;
    r->cfDiv   = nAEQDiv;
    r->cfIntDiv= nAEQIntDiv;
    r->cfIntMod= nAEQIntMod;
    r->cfExactDiv= nAEQExactDiv;
    r->cfInit = nAEQInit;
    r->cfSize  = nAEQSize;
    r->cfInt  = nAEQInt;
#ifdef HAVE_RINGS
    //r->cfDivComp = NULL; // only for ring stuff
    //r->cfIsUnit = NULL; // only for ring stuff
    //r->cfGetUnit = NULL; // only for ring stuff
    //r->cfExtGcd = NULL; // only for ring stuff
    // r->cfDivBy = NULL; // only for ring stuff
#endif
    r->cfNeg   = nAEQNeg;
    r->cfInvers= NULL;
    //r->cfCopy  = ndCopy;
    //r->cfRePart = ndCopy;
    //r->cfImPart = ndReturn0;
    r->cfWriteLong = nAEQWriteLong;
    r->cfRead = nAEQRead;
    //r->cfNormalize=ndNormalize;
    r->cfGreater = nAEQGreater;
    r->cfEqual = nAEQEqual;
    r->cfIsZero = nAEQIsZero;
    r->cfIsOne = nAEQIsOne;
    r->cfIsMOne = nAEQIsOne;
    r->cfGreaterZero = nAEQGreaterZero;
    r->cfPower = nAEQPower; // ZU BEARBEITEN
    r->cfGetDenom = nAEQGetDenom;
    r->cfGetNumerator = nAEQGetNumerator;
    r->cfGcd  = nAEQGcd;
    r->cfLcm  = nAEQLcm; // ZU BEARBEITEN
    r->cfDelete= nAEQDelete;
    r->cfSetMap = npSetMap;
    r->cfName = nAEQName;
    r->cfInpMult=nAEQInpMult; //????
    r->cfInit_bigint= NULL; // nAEQMap0;
    r->cfCoeffWrite=nAEQCoeffWrite; //????


    // the variables:
    r->nNULL = (number) 0;
    //r->type = n_AE;
    r->has_simple_Alloc=TRUE;
    r->has_simple_Inverse=TRUE;
    return FALSE;
}

