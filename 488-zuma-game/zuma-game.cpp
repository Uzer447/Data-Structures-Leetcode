class Solution {
public:
    int findMinStep(string board, string hand) {
        int ans = 0;
        auto init_board = ZumaBoard( board );
        auto init_hand = ZumaHand( hand );

        queue<pair<ZumaBoard, ZumaHand>> bfs;
        bfs.push({init_board, init_hand});
        unordered_set<unsigned long long> visited;
        visited.insert(init_board.board ^ (init_hand.hold << 11));

        while( bfs.size() ){
            ++ans;
            for( int i = bfs.size(); i; --i ){
                auto [chain, hold] = bfs.front();
                bfs.pop();

                for( int type = 1; type <= 5; ++type ){
                    if( !hold[type] )
                        continue;

                    for( int pos = 1; pos < 21; ++pos ){
                        if( chain[pos] == type || (chain[pos - 1] != type && chain[pos] != chain[pos - 1]) )
                            continue;

                        auto new_chain = ZumaBoard( chain );
                        new_chain.insert( pos, type );

                        auto new_hold = ZumaHand( hold );
                        new_hold.pop( type );
                        // cout << new_chain << '\n' << new_hold << '\n';

                        new_chain.remove( pos );
                        if( new_chain.empty() )
                            return ans;

                        if( !(visited.insert(new_chain.board ^ (new_hold.hold << 11))).second )
                            continue;

                        bfs.push({new_chain, new_hold});
                        
                        if( !chain[pos] )
                            break;
                    }
                }
            }
        }

        return -1;
    }

    static const map<char, int> id;

    struct ZumaBoard{
        unsigned long long board;

        ZumaBoard( string &s ) : board(0){
            for( auto &c : s )
                board = (board << 3) | id.at(c);
        }

        ZumaBoard( int n ) : board(n){}
        ZumaBoard( const ZumaBoard &b ) : board(b.board){}

        bool empty(){
            return board == 0;
        }

        void insert( int pos, unsigned long long type ){
            auto mask = (1ULL << 3*pos) - 1;
            board = ( (board&(~mask)) << 3 ) | ( type << 3*pos ) | ( board&mask );
        }

        void remove( int pos ){
            auto &self = *this;
            
            while(1){
                int l = pos;
                int r = pos;
                char c = self[pos];
                int len = 1;

                while( c && l < 21 && self[l + 1] == c ){
                    ++l;
                    ++len;
                }
                while( r && self[r - 1] == c ){
                    --r;
                    ++len;
                }

                if( len < 3 )
                    return;

                auto mask_l = ~((1ULL << 3*(l+1)) - 1);
                auto mask_r = (1ULL << 3*r) - 1;

                board = ((board&mask_l) >> (3*len)) | (board&mask_r);
                pos = r;
            }
        }

        char operator[]( int pos ) const {
            return (board >> (3 * pos)) & 0b111;
        }

        bool operator==(const ZumaBoard &b) const {
            return board == b.board;
        }

        friend ostream &operator<<( ostream &os, const ZumaBoard &n ){
            for( int i = 0; i <= 21; ++i ){
                auto val = n[i];
                if (!val)
                    break;

                switch( val ){
                    case 1: os << "R"; break;
                    case 2: os << "Y"; break;
                    case 3: os << "B"; break;
                    case 4: os << "G"; break;
                    case 5: os << "W"; break;
                    default: os << "ERROR"; break;
                }
            }
            return os;
        }
    };

    struct ZumaHand{
        int hold;

        ZumaHand( string &s ):hold(0){
            for( auto &c : s )
                hold += 1 << (3*id.at(c));
        }
        ZumaHand( int n ) : hold(n){}
        ZumaHand( const ZumaHand &b ) : hold(b.hold){}

        void pop( int type ){
            hold -= 1 << 3*type;
        }
        
        int operator[]( int type ) const{
            return (hold >> (3 * type)) & 0b111;
        }

        bool operator==(const ZumaHand &b) const {
            return hold == b.hold;
        }

        friend ostream &operator<<( ostream &os, const ZumaHand &n ){
            os << "Hold: ";
            os << "R: " << n[1] << ' ';
            os << "Y: " << n[2] << ' ';
            os << "B: " << n[3] << ' ';
            os << "G: " << n[4] << ' ';
            os << "W: " << n[5] << ' ';
            return os;
        }
    };
};

const map<char, int> Solution::id = {{'R', 1}, {'Y', 2}, {'B', 3}, {'G', 4}, {'W', 5}};