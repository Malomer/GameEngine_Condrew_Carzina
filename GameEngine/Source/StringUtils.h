#pragma once

#include <string>

class HashedString {

public:
	explicit HashedString(char const * const pIdentString)
		: m_ident(hash_name(pIdentString))
		, m_identStr(pIdentString) {
	}

	unsigned long getHashValue(void) const {
		return reinterpret_cast<unsigned long>(m_ident);
	}

	const std::string &getStr() const {
		return m_identStr;
	}

	static
		void *hash_name(char const *pIdentStr) {
			unsigned long BASE = 65521L;
			unsigned long NMAX = 5552;

			#define DO1(buf,i)  {s1 += tolower(buf[i]); s2 += s1;}
			#define DO2(buf,i)  DO1(buf,i); DO1(buf,i+1);
			#define DO4(buf,i)  DO2(buf,i); DO2(buf,i+2);
			#define DO8(buf,i)  DO4(buf,i); DO4(buf,i+4);
			#define DO16(buf)   DO8(buf,0); DO8(buf,8);

			if (pIdentStr == NULL)
				return NULL;

			unsigned long s1 = 0;
			unsigned long s2 = 0;

			for (size_t len = strlen(pIdentStr); len > 0;) {
				unsigned long k = len < NMAX ? len : NMAX;
				len -= k;

				while (k >= 16) {
					DO16(pIdentStr);
					pIdentStr += 16;
					k -= 16;
				}

				if (k != 0) do {
					s1 += tolower(*pIdentStr++);
					s2 += s1;
				} while (--k);

				s1 %= BASE;
				s2 %= BASE;
			}
			return reinterpret_cast<void *>((s2 << 16) | s1);
	}

	bool operator< (HashedString const & o) const {
		bool r = (getHashValue() < o.getHashValue());
		return r;
	}

	bool operator== (HashedString const &o) const {
		bool r = (getHashValue() == o.getHashValue());
		return r;
	}

private:

	void *m_ident;
	std::string	m_identStr;
};
