/* An entry in a hash table.  */
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include<vector>
#include<string>
using std::vector;
using namespace std;

//表示Inst的ivec有效
#define type_is_vector 0

//表示Inst的name有效
//表示没有引号的string，可能是关键词，操作符等
#define type_is_string1 1
//表示有引号的string
#define type_is_string2 2

class hash_entry;
class hash_control;

class Inst{
private:
	vector<Inst> ivec;
	string name;
	int type;
public:
	void set_type(int t);
	void name_cat(char c);
	void gen();
	void display(int lev);
};

void Inst::set_type(int t){
	type=t;
}

void Inst::name_cat(char c){
	name+=c;
}

void Inst::gen(){
	char c1;
	while((c1=getchar())!=EOF){
		if(c1==')') return;
		//一个vector开始
		else if(c1=='('){
			Inst inst_1;
			inst_1.set_type(type_is_vector);
			ivec.push_back(inst_1);
			ivec[ivec.size()-1].gen();
		}
		//带单引号的string
		else if(c1=='\''){
			if(ivec.size()>0&&ivec[ivec.size()-1].type!=type_is_vector){
				char c5;
				while((c5=getchar())!=EOF&&c5!=' '&&c5!='\n'&&c5!=')');
				if(c5==')')
				return ;
			}
			else {
				Inst inst_2;
				inst_2.set_type(type_is_string2);
				char c2;
			
				while((c2=getchar())!=EOF&&c2!='\'')
				 inst_2.name_cat(c2);
				ivec.push_back(inst_2);
			}
		}
		//普通string
		else if(c1!='\n'&&c1!=' '){
			if(ivec.size()>0&&ivec[ivec.size()-1].type!=type_is_vector){
				char c4;
				while((c4=getchar())!=EOF&&c4!=' '&&c4!='\n'&&c4!=')');
				if(c4==')')
				return ;
			}
			else {
				Inst inst_3;
				inst_3.set_type(type_is_string1);
				inst_3.name_cat(c1);
				char c3;

				while((c3=getchar())!=EOF&&c3!=' '&&c3!='\n'&&c3!=')') 
					inst_3.name_cat(c3);
				ivec.push_back(inst_3);
				if(c3==')')
				return ;
			}
		}
		
	}
}


class hash_entry {
public:
  /* Next entry for this hash code.  */
  class hash_entry *next;
  /* String being hashed.  */
  const char *string;
  /* Hash code.  This is the full hash code, not the index into the
     table.  */
  unsigned long hash;
  /* Pointer being stored in the hash table.  */
  class Inst *data;	/*[void *data;]*/
};

/* A hash table.  */

class hash_control {
private:

/* The default number of entries to use when creating a hash table.
TODO  Note this value can be reduced to 4051 by using the command line
   switch --reduce-memory-overheads, or set to other values by using
   the --hash-size=<NUMBER> switch.  */


  /* The hash array.  */
  class hash_entry **table;
  /* The number of slots in the hash table.  */
  unsigned int size;

#ifdef HASH_STATISTICS
  /* Statistics.  */
  unsigned long lookups;
  unsigned long hash_compares;
  unsigned long string_compares;
  unsigned long insertions;
  unsigned long replacements;
  unsigned long deletions;
#endif /* HASH_STATISTICS */
	class hash_entry *loopup (const char *key, size_t len,   //size_t 是什么？
	     class hash_entry ***plist, unsigned long *phash);
	unsigned int get_size ();
	void set_size (unsigned long size);
	void init ();
public:
	hash_control(unsigned int table_size=65537);
	~hash_control();
	const char *insert (const char *key, class Inst *val /*[void *val]*/);
	class Inst *find (const char *key);
	class Inst *replace (const char *key, class Inst *value);
	class Inst *int erase (const char *key);
};

hash_control::~hash_control()
{
	/*TODO*/
}

hash_control::hash_control(unsigned int table_size)
{
	size=table_size;
	init();
}

/* Look up a string in a hash table.  This returns a pointer to the
   hash_entry, or NULL if the string is not in the table.  If PLIST is
   not NULL, this sets *PLIST to point to the start of the list which
   would hold this hash entry.  If PHASH is not NULL, this sets *PHASH
   to the hash code for KEY.

   Each time we look up a string, we move it to the start of the list
   for its hash code, to take advantage of referential locality.  */

class hash_entry *hash_control::
loopup (const char *key, size_t len,
	     class hash_entry ***plist, unsigned long *phash)
{
  unsigned long hash;
  size_t n;
  unsigned int c;
  unsigned int hindex;
  class hash_entry **list;
  class hash_entry *p;
  class hash_entry *prev;

#ifdef HASH_STATISTICS
  ++lookups;
#endif

  hash = 0;
  for (n = 0; n < len; n++)
    {
      c = key[n];
      hash += c + (c << 17);
      hash ^= hash >> 2;
    }
  hash += len + (len << 17);
  hash ^= hash >> 2;

  if (phash != NULL)
    *phash = hash;

  hindex = hash % size;
  list = table + hindex;

  if (plist != NULL)
    *plist = list;

  prev = NULL;
  for (p = *list; p != NULL; p = p->next)
    {
#ifdef HASH_STATISTICS
      ++hash_compares;
#endif

      if (p->hash == hash)
	{
#ifdef HASH_STATISTICS
	  ++string_compares;
#endif

	  if (strncmp (p->string, key, len) == 0 && p->string[len] == '\0')
	    {
	      if (prev != NULL)
		{
		  prev->next = p->next;/*lur*/
		  p->next = *list;
		  *list = p;
		}

	      return p;
	    }
	}

      prev = p;
    }

  return NULL;
}

unsigned int hash_control::
get_size (void)
{
  /* Extend this prime list if you want more granularity of hash table size.  */
  static const unsigned int hash_size_primes[] =
    {
      1021, 4051, 8599, 16699, 65537
    };

  /* Work out the best prime number near the hash_size.
     FIXME: This could be a more sophisticated algorithm,
     but is it really worth implementing it ?   */
	unsigned int hindex = 0;
  for (; hindex < sizeof(hash_size_primes)/sizeof(hash_size_primes[0]) - 1; ++ hindex)
    if (size <= hash_size_primes[hindex])
      break;

  return hash_size_primes[hindex];
}

/* Create a hash table.  This return a control block.  */

void hash_control::init ()
{
  size = get_size ();

  if( NULL == ( table = new class hash_entry * [size]) )
  {
  	perror("hash_control:");
  	exit(1);
  }
  memset ( table, 0, size*sizeof(table[0]) );

#ifdef HASH_STATISTICS
  lookups = 0;
  hash_compares = 0;
  string_compares = 0;
  insertions = 0;
  replacements = 0;
  deletions = 0;
#endif
}

/* Insert an entry into a hash table.  This returns NULL on success.
   On error, it returns a printable string indicating the error.  It
   is considered to be an error if the entry already exists in the
   hash table.  */

const char * hash_control::insert (const char *key, class Inst *val /*[void *val]*/)
{
  class hash_entry *p;
  class hash_entry **list;
  unsigned long hash;

  p = loopup (key, strlen (key), &list, &hash);
  if (p != NULL)
    return "exists";

#ifdef HASH_STATISTICS
  ++insertions;
#endif

  p = new class hash_entry;
  p->string = key;
  p->hash = hash;
  p->data = val;

  p->next = *list;
  *list = p;

  return NULL;
}

/* Find an entry in a hash table, returning its value.  Returns NULL
   if the entry is not found.  */

class Inst *hash_control::find (const char *key)
{
  class hash_entry *p;

  p = loopup (key, strlen (key), NULL, NULL);
  if (p == NULL)
    return 0;

  return p->data;
}

/* Replace an existing entry in a hash table.  This returns the old
   value stored for the entry.  If the entry is not found in the hash
   table, this does nothing and returns NULL.  */

class Inst *hash_control::replace (const char *key, class Inst *value
 /*[void *value]*/)
{
  class hash_entry *p;
  class Inst *ret;/*[void *ret;]*/

  p = loopup ( key, strlen (key), NULL, NULL);
  if (p == 0)
    return 0;

#ifdef HASH_STATISTICS
  ++replacements;
#endif

  ret = p->data;

  p->data = value;

  return ret;
}

/* Delete an entry from a hash table.  This returns the value stored
   for that entry, or NULL if there is no such entry.*/  

class Inst *hash_control::erase (const char *key)
{
  class hash_entry *p;
  class hash_entry **list;

  p = loopup (key, strlen (key), &list, NULL);
  if (p == 0)
    return 0;

  if (p != *list)
    abort ();

#ifdef HASH_STATISTICS
  ++deletions;
#endif

  *list = p->next;
  class Inst *tmp=p->data;
	delete p;
  return tmp;
}

int main(){
