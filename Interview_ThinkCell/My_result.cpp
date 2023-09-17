#include <map>
#include <limits>
#include <cassert>

template<typename K, typename V>
class IntervalMap {
    std::map<K, V> m_map;

public:
    IntervalMap(V const& val) {
        m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

    void assign(K const& keyBegin, K const& keyEnd, V const& val) {
        if (!(keyBegin < keyEnd)) return;

        auto itBegin = m_map.lower_bound(keyBegin);
        auto itEnd = m_map.lower_bound(keyEnd);

        if (itBegin != m_map.begin() && (--itBegin)->second == val) {
            ++itBegin;
        }

        m_map.erase(itBegin, itEnd);
        m_map[keyBegin] = val;
    }

    V const& operator[](K const& key) const {
        return (--m_map.upper_bound(key))->second;
    }
};

int main() {
    // Initialize with 'A'
    IntervalMap<int, char> imap('A');

    // Assign 'B' to [1, 3)
    imap.assign(1, 3, 'B');

    // Assign 'C' to [5, 7)
    imap.assign(5, 7, 'C');

    // Assign 'D' to [10, 12)
    imap.assign(10, 12, 'D');

    // Verify assignments
    assert(imap[0] == 'A');
    assert(imap[1] == 'B');
    assert(imap[2] == 'B');
    assert(imap[3] == 'A');
    assert(imap[4] == 'A');
    assert(imap[5] == 'C');
    assert(imap[6] == 'C');
    assert(imap[7] == 'A');
    assert(imap[8] == 'A');
    assert(imap[9] == 'A');
    assert(imap[10] == 'D');
    assert(imap[11] == 'D');
    assert(imap[12] == 'A');
    assert(imap[13] == 'A');

    // Test assigning back to 'A'
    imap.assign(3, 10, 'A');

    // Verify assignments
    assert(imap[0] == 'A');
    assert(imap[1] == 'B');
    assert(imap[2] == 'B');
    assert(imap[3] == 'A');
    assert(imap[4] == 'A');
    assert(imap[5] == 'A');
    assert(imap[6] == 'A');
    assert(imap[7] == 'A');
    assert(imap[8] == 'A');
    assert(imap[9] == 'A');
    assert(imap[10] == 'A');
    assert(imap[11] == 'A');
    assert(imap[12] == 'A');
    assert(imap[13] == 'A');

    return 0;
}

