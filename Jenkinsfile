pipeline {
    agent {
        
        label 'docker-test-cloud' // The label assigned to the Docker agent in Jenkins
        
    }
    stages {
        stage('Installation'){
            steps{
                sh 'git clone https://github.com/martinge17/C_ADTs.git'
            }
        }
        stage('Compile Project') {
            steps {
                sh 'gcc -o /C_ADTs/Lists/List/Exer/main /C_ADTs/Lists/List/Exer/main.c /C_ADTs/Lists/List/Exer/linked_list.c'
                sh '/C_ADTs/Lists/List/Exer/main'
            }
        }
    }
}
