//---------------------------------------------------------------------------
// ICPC 2015 Mid-Central Regional
// Pyro Tubes solution
// R. Marshall
//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>


#define MAX_DIST 2 // max number of different bits (AKA changes) allowed
#define NUM_BITS 18 // number of bits (AKA tubes)

using namespace std;

// Find the Hamming Neighborhood of L at distance D.
//
// iteratively builds list B from A[1,..NUM_BITS] so,
// Let D = 2
// B[1] contains ints that are distance D from the smallest bit in L,
// B[2] contains ints that are distance D from the smallest 2 bits in L,
// B[NUM_BITS] contains ints that are distance D from the
//   smallest NUM_BITS bits in L
//
vector<int> hamming_nbhd(int L, int D) {
   vector<vector<int> >A, B(NUM_BITS+1, vector<int>(1));

   for (int i=0;i<NUM_BITS+1;++i)
       B[i][0] = L % (1 << i);

   for (int d = 1; d < (D + 1); ++d) {
      A = B;
      vector<vector<int> >::iterator itr = B.begin();

      for ( ; itr != B.end(); ++itr) // remove values no longer needed
         itr->clear();

      for (int b = d; b < NUM_BITS + 1; ++b) {
         vector<int>::iterator it;
         // flip the b-1th bit in every A and B from the previous round
         for (it = (A[b - 1]).begin(); it != (A[b - 1]).end(); ++it)
               B[b].push_back(*it + ((L & (1 << (b - 1))) ^ (1 << (b - 1))));

         for (it = (B[b - 1]).begin(); it != (B[b - 1]).end(); ++it)
               B[b].push_back(*it + (L & (1 << (b - 1))));
      }
   }

   return B[NUM_BITS];
}


int main(int argc, char* argv[])
{
   vector<int> L_vals;
   int L = 0;
   int y = 0; // debug counter
   cin >> L;

   // Read in the entire list first.
   while ( L != -1) {
      L_vals.push_back(L);
      cin >> L;
   }

   std::sort(L_vals.begin(),L_vals.end());
   vector<int>::iterator a = L_vals.begin();

   for ( ; a != L_vals.end() - 1; ++a) {
      cout << *a << ":"; // original luminosity

      int count = 0;
      vector<int> neighbors;
      for (int z = 1; z <= MAX_DIST; ++z)
      {
         vector<int> b = hamming_nbhd(*a,z);
         neighbors.insert(neighbors.end(), b.begin(), b.end());
      }

      std::sort(neighbors.begin(),neighbors.end());
      vector<int>::iterator nb = neighbors.begin();

      for ( ; nb != neighbors.end(); ++nb)
         if (*a < *nb && (std::binary_search(a,L_vals.end(),*nb)) )
            count++;

      cout << count << endl;
      y++;

      if (y%1000 == 0)
         cerr << y << endl; // for debug
   }

   cout << *(L_vals.end() - 1) << ":0" << endl; // the last one is always 0

   return 0;
}
