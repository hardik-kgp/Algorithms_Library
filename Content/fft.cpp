using cd = complex<ld>;
const ld PI = acos(-1);
 
void fft(vector<cd> & a, bool invert) {
    ll n = a.size();
    if (n == 1)
        return;
 
    vector<cd> a0(n / 2LL), a1(n / 2LL);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2LL*i];
        a1[i] = a[2LL*i+1LL];
    }
    fft(a0, invert);
    fft(a1, invert);
 
    ld ang = 2LL * PI / n * (invert ? -1LL : 1LL);
    cd w(1LL), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
 
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
ll n = 1;
while (n < a.size() + b.size()) 
    n <<= 1;
fa.resize(n);
fb.resize(n);

fft(fa, false);
fft(fb, false);
for (int i = 0; i < n; i++)
    fa[i] *= fb[i];
fft(fa, true);

vector<ll> result(n);
for (int i = 0; i < n; i++)
    result[i] = round(fa[i].real());
return result;
}