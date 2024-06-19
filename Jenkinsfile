pipeline {
    agent {
        docker {
            label 'docker' // The label assigned to the Docker cloud in Jenkins
            dockerfile true
        }
    }
    stages {
        stage('Compile Project') {
            steps {
                sh 'gcc -o /C_ADTs/Lists/List/Exer/main /C_ADTs/Lists/List/Exer/main.c /C_ADTs/Lists/List/Exer/linked_list.c'
                sh '/C_ADTs/Lists/List/Exer/main'
            }
        }
    }
}
