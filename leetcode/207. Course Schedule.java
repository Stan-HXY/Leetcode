import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        HashMap<Integer, List<Integer>> M = new HashMap<>();
        boolean[] visited = new boolean[numCourses];
        boolean[] checked = new boolean[numCourses];

        for(int[] i : prerequisites){
            if(M.containsKey(i[0])){
                // put prerequisite course into this course's list
                 M.get(i[0]).add(i[1]);  
            }
            else{
                // put prerequisite course into this course's list
                List<Integer> l = new ArrayList<Integer>();
                l.add(i[1]);
                M.put(i[0], l);
            }
        }
        for(int i = 0; i < numCourses; ++i){
            if(dfs(M, visited, checked, i) == false){
                return false;
            }
        }     
        return true;
    }


    public boolean dfs(HashMap<Integer, List<Integer>> M, boolean[] visited, boolean[] checked, int course){
        if(visited[course] == true) return false;
        if(checked[course] == true) return true;
        if(M.get(course) == null) return true;

        visited[course] = true;
        for(int i = 0; i < M.get(course).size(); ++i){
            int pre_course = M.get(course).get(i);
            if(checked[pre_course] == false && dfs(M, visited, checked, pre_course) == false){
                return false;
            }
        }
        visited[course] = false;
        checked[course] = true;

        return true;
    }


}