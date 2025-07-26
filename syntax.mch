
field Owner (
    string name;
    int id;
)

field Invoice {
    double balance;
    string currency;
}


field Timestamp {
    int created_at;
    int updated_at;
}

field Flags {
    bool active;
    bool archived;
}

field Rate {
    double interestRate;
}


object BankAccount {
    Owner owner = { name: "Oleg", id: 1 };
    Invoice in[] = {{256.1, "EUR"}, {1672.1, "USD"}};
    Timestamp ts = { created_at: 1000, updated_at: 1050 };
    Flags flags = { active: true, archived: false };
}

object SavingAccount {
    include BankAccount \ Flags;
    Rate rate = 0.124;
}

system newMonth {
    query (Invoice); // default as item
    query saving (Rate); // as saving

    run (int indexing);
    
}

system anotherMonth {

    query (Invoice); // default as item

    query saving (Rate); // as saving

    run (int indexing) {
        item.owner.name = "Igor";
    }
}

newMonth run (int indexing) {

    for (auto val : item.in) { // .in = item.in 
        if (val.currency == "USD"){
            val.balance *= indexing;
        }
    }

    for (auto val : saving.in) {
        val.balance *= saving.rate;
    }

}


