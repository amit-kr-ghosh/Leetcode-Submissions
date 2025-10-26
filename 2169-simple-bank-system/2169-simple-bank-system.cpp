class Bank {
public:
    vector<long long> bal;
    int n;
    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }

    bool isValid(int account) {
        return account >= 1 && account <= n;
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2) || bal[account1 - 1] < money)
            return false;
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValid(account))
            return false;
        bal[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValid(account) || bal[account - 1] < money)
            return false;
        bal[account - 1] -= money;
        return true;
    }
};
