   bool ispairSum(int arr[],int start,int end,int target){

        int s=start;

        int e=end-1;

        while(s<e){

            if(arr[s]+arr[e]==target){

                return 1;

            }else if(arr[s]+arr[e]<target){

                s++;

            }else{

                e--;

            }

        }

    return 0;

    }

    bool findTriplets(int arr[], int n)

    { 

        sort(arr,arr+n);

        for(int i=0;i<n-2;i++){

            if(ispairSum(arr,i+1,n,0-arr[i])){

                return 1;

            }

        }

    return 0;

    }
