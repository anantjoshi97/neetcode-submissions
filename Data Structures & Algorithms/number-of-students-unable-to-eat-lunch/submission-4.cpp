class Q{
    public:
    int val;
    int s0;
    int s1;
    Q* next;
    Q* prev;

    Q(){
        val = 0;
        s0 = 0;
        s1 = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution{
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            vector<int> counts(2);

            for (const int &stu : students){
                counts[stu]++;
            }

            int hungry = students.size();
            for (int j=0; j<sandwiches.size(); j++){
                int sw = sandwiches[j];
                counts[sw]--;
                if (counts[sw] < 0){
                    if (sw==0){return counts[1];}
                    else {return counts[0];}
                }
                else if (counts[0]==0 && counts[1]==0){
                    return 0;
                }
            }
        }
};

class Solution1 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        if (students.size()==0 || sandwiches.size()==0){
            return students.size();
        }
        if (students.size()==1){
            if (students[0]==sandwiches[0]){return 0;}
            else {return 1;}
        }
        Q* head = new Q();
        Q* tail;
        Q* curr;

        head->val = students[0];
        if (students[0]==0){head->s0++;}
        else{head->s1++;}
        curr = head;

        for(int i=1; i<students.size();i++){
            Q* ahead = new Q();
            curr->next = ahead;
            ahead->prev = curr;
            ahead->val = students[i];
            if (students[i]==0){ahead->s0 = curr->s0 + 1;ahead->s1=curr->s1;}
            else{ahead->s1 = curr->s1 + 1;ahead->s0=curr->s0;}
            curr = ahead;
        }
        tail = curr;

        int j=0;
        while (j<sandwiches.size()){
            int sw = sandwiches[j];

            
            
            if (tail->s1==0 && sw==1){
                return tail->s0;
            }
            else if(tail->s0==0 && sw==0){
                return tail->s1;
            }
            
            if (tail->val == sw){
                j++;
                if (sw==0){tail->s0--;}
                else {tail->s1--;}
                Q* old_tail = tail;
                tail = tail->prev;
                if (tail==nullptr){
                    return 0;
                }
                tail->s0 = old_tail->s0;
                tail->s1 = old_tail->s1;
                tail->next = nullptr;
                delete old_tail;
            }
            else{
                Q* old_tail = tail;
                tail = tail-> prev;
                tail->s0 = old_tail->s0;
                tail->s1 =old_tail->s1;
                old_tail->prev = nullptr;
                tail->next = nullptr;
                old_tail->next=head;
                head->prev=old_tail;
                head = old_tail;
            }

        }

        return 0;        

    }
};