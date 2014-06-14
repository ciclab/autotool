void set_val( long long &v, char *c, int len)
{
  v ^= v;
  for( int i = 0; i < len; ++i )
    {
      v = ( v << 1 ) | ( c[i] == '0' ? 0 : 1 );
    }
}
