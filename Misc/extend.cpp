#define INF 0x3f3f3f3f
#define lowbit(x) ((x) & -(x))
#define tmin(a, b) (a) = min((a), (b))
#define tmax(a, b) (a) = max((a), (b))
typedef pair<int, int> pii;

void db() { cerr << endl; }
template <class T, class... U>
void db(T a, U... b) { cerr << a << " ", db(b...); }
