template <class T>
bool tooBig(const T & val, const T & lim)
{
	return val > lim;
}

template <class T>
class TooBig2
{
private:
	T cutoff;
public:
	TooBig2(const T & t) : cutoff(t) {}
	bool operator()(const T & v) {
		return tooBig<T>(v, cutoff);
	}
};