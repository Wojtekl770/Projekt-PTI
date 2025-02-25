#include "Food.h"

Base::Base(string n, int k, double tl, double we, double bl, double bia, int ind) :nazwa{ n }, kcal{ k }, tluszcz{ tl }, weglowodany{ we }, blonnik{ bl }, bialko{ bia }, index{ind} {}


ostream& operator<<(ostream& out, const Base& obj) {
	out << obj.index << "." << obj.nazwa << endl;
	return out;
}


Owoce::Owoce(string n, int k, double tl, double cho, double we, double bl, double bia, int ind, double mg, double zel, double wapn) : Base(n, k, tl, we, bl, bia, ind), cholesterol{ cho }, magnez{ mg }, zelazo{ zel }, wapn{ wapn } {}

Food::Food(string n, int k, double tl, double we, double cu, double bl, double bia,int ind, double s, bool gl, bool ja, bool so, bool na, bool orz, bool mies) :Base(n, k, tl, we, bl, bia, ind), cukry{ cu }, sol{ s }, alergia_gluten{ gl }, alergia_jaja{ ja }, alergia_soja{ so }, alergia_nabial{ na }, alergia_orzech{ orz }, czy_ma_mieso{ mies } {}


