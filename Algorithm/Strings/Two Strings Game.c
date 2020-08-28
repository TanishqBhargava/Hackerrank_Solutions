#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A_SIZE 26
#define MIN_C 'a'
typedef struct _st_node st_node;
typedef struct _st_edge st_edge;
struct _st_node{
  int x;
  unsigned long long count;
  st_node *suffix_link;
  st_edge *edges[A_SIZE+1];
};
struct _st_edge{
  int from;
  int to;
  int suffix_index;
  st_node *node;
};
int dfs0(st_node *root,int flag);
unsigned long long dfs1(st_node *root);
void dfs2(int idx,st_node *root);
unsigned long long dfs3(st_node *root);
void dfs4(int idx,st_node *root);
void suffix_tree(st_node *root,char *str,int len);
char a[300001],b[300001],ans[300001];
unsigned long long dp[50],total,K,KK,val;

int main(){
  int N,M,i;
  st_node r1,r2;
  scanf("%d%d%lld%s%s",&N,&M,&K,a,b);
  suffix_tree(&r1,a,N);
  suffix_tree(&r2,b,M);
  dfs0(&r1,0);
  dfs0(&r2,1);
  for(i=0;i<50;i++)
    total+=dp[i];
  dfs1(&r1);
  if(r1.count<K){
    printf("no solution\n");
    return 0;
  }
  dfs2(0,&r1);
  dfs3(&r2);
  KK=0;
  dfs4(0,&r2);
  return 0;
}
int dfs0(st_node *root,int flag){
  char arr[20];
  int len,ret,i;
  if(!root){
    if(flag)
      dp[0]++;
    return 0;
  }
  memset(arr,0,sizeof(arr));
  for(i=0;i<A_SIZE;i++)
    if(root->edges[i]){
      len=root->edges[i]->to-root->edges[i]->from+1;
      ret=dfs0(root->edges[i]->node,flag);
      if(len==1)
        arr[ret]=1;
      else
        if(ret){
          if(flag){
            dp[0]+=len/2;
            dp[1]+=(len-1)/2;
          }
          if(len%2)
            arr[1]=1;
          else
            arr[0]=1;
        }
        else{
          if(flag){
            dp[1]+=len/2;
            dp[0]+=(len-1)/2;
          }
          if(len%2)
            arr[0]=1;
          else
            arr[1]=1;
        }
    }
  for(i=0;i<20 && arr[i];i++);
  if(flag)
    dp[i]++;
  root->x=i;
  return i;
}
unsigned long long dfs1(st_node *root){
  int len,ret,i;
  unsigned long long ret2,count=0;
  if(!root)
    return total-dp[0];
  for(i=0;i<A_SIZE;i++)
    if(root->edges[i]){
      len=root->edges[i]->to-root->edges[i]->from+1;
      ret2=dfs1(root->edges[i]->node);
      if(root->edges[i]->node)
        ret=root->edges[i]->node->x;
      else
        ret=0;
      count+=ret2;
      if(ret){
        count+=len/2*(total-dp[0]);
        count+=(len-1)/2*(total-dp[1]);
      }
      else{
        count+=len/2*(total-dp[1]);
        count+=(len-1)/2*(total-dp[0]);
      }
    }
  count+=total-dp[root->x];
  root->count=count;
  return count;
}
void dfs2(int idx,st_node *root){
  int len,ret,start,i,j;
  unsigned long long t1,t2;
  if(!root){
    ans[idx]=0;
    printf("%s\n",ans);
    val=0;
    K-=KK;
    return;
  }
  if(KK+total-dp[root->x]>=K){
    ans[idx]=0;
    printf("%s\n",ans);
    val=root->x;
    K-=KK;
    return;
  }
  KK+=total-dp[root->x];
  for(i=0;i<A_SIZE;i++)
    if(root->edges[i]){
      len=root->edges[i]->to-root->edges[i]->from+1;
      if(root->edges[i]->node){
        ret=root->edges[i]->node->x;
        t2=root->edges[i]->node->count;
      }
      else{
        ret=0;
        t2=total-dp[0];
      }
      t1=0;
      if(ret){
        t1+=len/2*(total-dp[0]);
        t1+=(len-1)/2*(total-dp[1]);
      }
      else{
        t1+=len/2*(total-dp[1]);
        t1+=(len-1)/2*(total-dp[0]);
      }
      if(KK+t1+t2<K)
        KK+=t1+t2;
      else if(KK+t1<K){
        KK+=t1;
        for(j=root->edges[i]->from;j<=root->edges[i]->to;j++)
          ans[idx+j-root->edges[i]->from]=a[j];
        dfs2(idx+root->edges[i]->to-root->edges[i]->from+1,root->edges[i]->node);
        return;
      }
      else{
        if((ret && len%2) || (!ret && len%2==0))
          start=1;
        else
          start=0;
        for(j=root->edges[i]->from;j<root->edges[i]->to;j++,start^=1){
          ans[idx+j-root->edges[i]->from]=a[j];
          if(KK+total-dp[start]>=K){
            ans[idx+j+1-root->edges[i]->from]=0;
            printf("%s\n",ans);
            val=start;
            K-=KK;
            return;
          }
          KK+=total-dp[start];
        }
        return;
      }
    }
  return;
}
unsigned long long dfs3(st_node *root){
  int len,ret,i;
  unsigned long long ret2,count=0;
  if(!root){
    if(val)
      return 1;
    return 0;
  }
  for(i=0;i<A_SIZE;i++)
    if(root->edges[i]){
      len=root->edges[i]->to-root->edges[i]->from+1;
      ret2=dfs3(root->edges[i]->node);
      if(root->edges[i]->node)
        ret=root->edges[i]->node->x;
      else
        ret=0;
      count+=ret2;
      if(ret){
        if(val!=0)
          count+=len/2;
        if(val!=1)
          count+=(len-1)/2;
      }
      else{
        if(val!=1)
          count+=len/2;
        if(val!=0)
          count+=(len-1)/2;
      }
    }
  if(val!=root->x)
    count++;
  root->count=count;
  return count;
}
void dfs4(int idx,st_node *root){
  int len,ret,start,i,j;
  unsigned long long t1,t2;
  if(!root){
    ans[idx]=0;
    printf("%s\n",ans);
    return;
  }
  if(val!=root->x && KK+1==K){
    ans[idx]=0;
    printf("%s\n",ans);
    return;
  }
  if(val!=root->x)
    KK++;
  for(i=0;i<A_SIZE;i++)
    if(root->edges[i]){
      len=root->edges[i]->to-root->edges[i]->from+1;
      if(root->edges[i]->node){
        ret=root->edges[i]->node->x;
        t2=root->edges[i]->node->count;
      }
      else{
        ret=0;
        if(val)
          t2=1;
        else
          t2=0;
      }
      t1=0;
      if(ret){
        if(val!=0)
          t1+=len/2;
        if(val!=1)
          t1+=(len-1)/2;
      }
      else{
        if(val!=1)
          t1+=len/2;
        if(val!=0)
          t1+=(len-1)/2;
      }
      if(KK+t1+t2<K)
        KK+=t1+t2;
      else if(KK+t1<K){
        KK+=t1;
        for(j=root->edges[i]->from;j<=root->edges[i]->to;j++)
          ans[idx+j-root->edges[i]->from]=b[j];
        dfs4(idx+root->edges[i]->to-root->edges[i]->from+1,root->edges[i]->node);
        return;
      }
      else{
        if((ret && len%2) || (!ret && len%2==0))
          start=1;
        else
          start=0;
        for(j=root->edges[i]->from;j<root->edges[i]->to;j++,start^=1){
          ans[idx+j-root->edges[i]->from]=b[j];
          if(val!=start){
            if(KK+1==K){
              ans[idx+j+1-root->edges[i]->from]=0;
              printf("%s\n",ans);
              return;
            }
            KK++;
          }
        }
        return;
      }
    }
  return;
}
void suffix_tree(st_node *root,char *str,int len){
  int a_edge,a_len=0,remainder=0,need_insert,from,i;
  st_node *a_node=root,*pre_node,*t_node;
  st_edge *t_edge;
  memset(root,0,sizeof(st_node));
  for(i=0;i<len;i++){
    need_insert=0;
    pre_node=NULL;
    remainder++;
    if(i==len)
      need_insert=1;
    else if(a_len)
      if(str[a_node->edges[a_edge]->from+a_len]==str[i])
        if(a_node->edges[a_edge]->from+a_len==a_node->edges[a_edge]->to){
          a_node=a_node->edges[a_edge]->node;
          a_len=0;
        }
        else
          a_len++;
      else
        need_insert=1;
    else
      if(a_node->edges[str[i]-MIN_C])
        if(a_node->edges[str[i]-MIN_C]->from==a_node->edges[str[i]-MIN_C]->to)
          a_node=a_node->edges[str[i]-MIN_C]->node;
        else{
          a_edge=str[i]-MIN_C;
          a_len=1;
        }
      else
        need_insert=1;
    if(need_insert)
      for(;remainder>0;remainder--){
        if(!a_len)
          if(i==len){
            a_node->edges[A_SIZE]=(st_edge*)malloc(sizeof(st_edge));
            a_node->edges[A_SIZE]->suffix_index=i-remainder+1;
            a_node->edges[A_SIZE]->node=NULL;
          }
          else{
            if(a_node->edges[str[i]-MIN_C]){
              if(pre_node)
                pre_node->suffix_link=a_node;
              if(a_node->edges[str[i]-MIN_C]->from==a_node->edges[str[i]-MIN_C]->to)
                a_node=a_node->edges[str[i]-MIN_C]->node;
              else{
                a_edge=str[i]-MIN_C;
                a_len=1;
              }
              break;
            }
            t_edge=(st_edge*)malloc(sizeof(st_edge));
            t_edge->from=i;
            t_edge->to=len-1;
            t_edge->suffix_index=i-remainder+1;
            t_edge->node=NULL;
            a_node->edges[str[i]-MIN_C]=t_edge;
            t_node=a_node;
          }
        else{
          if(i!=len && str[a_node->edges[a_edge]->from+a_len]==str[i]){
            if(pre_node)
              pre_node->suffix_link=a_node;
            if(a_node->edges[a_edge]->from+a_len==a_node->edges[a_edge]->to){
              a_node=a_node->edges[a_edge]->node;
              a_len=0;
            }
            else
              a_len++;
            break;
          }
          t_node=(st_node*)malloc(sizeof(st_node));
          memset(t_node,0,sizeof(st_node));
          t_edge=(st_edge*)malloc(sizeof(st_edge));
          t_edge->from=a_node->edges[a_edge]->from+a_len;
          t_edge->to=a_node->edges[a_edge]->to;
          t_edge->suffix_index=a_node->edges[a_edge]->suffix_index;
          t_edge->node=a_node->edges[a_edge]->node;
          from=a_node->edges[a_edge]->from;
          a_node->edges[a_edge]->node=t_node;
          a_node->edges[a_edge]->to=a_node->edges[a_edge]->from+a_len-1;
          t_node->edges[str[t_edge->from]-MIN_C]=t_edge;
          if(i==len){
            t_node->edges[A_SIZE]=(st_edge*)malloc(sizeof(st_edge));
            t_node->edges[A_SIZE]->suffix_index=i-remainder+1;
            t_node->edges[A_SIZE]->node=NULL;
          }
          else{
            t_edge=(st_edge*)malloc(sizeof(st_edge));
            t_edge->from=i;
            t_edge->to=len-1;
            t_edge->suffix_index=i-remainder+1;
            t_edge->node=NULL;
            t_node->edges[str[i]-MIN_C]=t_edge;
          }
        }
        if(pre_node)
          pre_node->suffix_link=t_node;
        pre_node=t_node;
        if(a_node==root && a_len>0){
          if(remainder>1)
            a_edge=str[i-remainder+2]-MIN_C;
          from=i-remainder+2;
          a_len--;
        }
        else if(a_node!=root)
          if(a_node->suffix_link)
            a_node=a_node->suffix_link;
          else
            a_node=root;
        while(a_len>0 && a_len>=a_node->edges[a_edge]->to-a_node->edges[a_edge]->from+1){
          a_len-=a_node->edges[a_edge]->to-a_node->edges[a_edge]->from+1;
          from+=a_node->edges[a_edge]->to-a_node->edges[a_edge]->from+1;
          a_node=a_node->edges[a_edge]->node;
          a_edge=str[from]-MIN_C;
        }
      }
  }
  return;
}
