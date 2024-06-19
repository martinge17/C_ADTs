pipeline {
    agent {
        docker {
            label 'docker' // The label assigned to the Docker cloud in Jenkins
        }
    }
    stages {
        stage('Build Docker Image') {
            steps {
                script {
                    // Build the Docker image
                    docker.build('Dockerfile')
                }
            }
        }
        stage('Compile Project') {
            agent {
                docker {
                    image 'Dockerfile'
                }
            }
            steps {
                sh 'gcc -o /C_ADTs/Lists/List/Exer/main /C_ADTs/Lists/List/Exer/main.c /C_ADTs/Lists/List/Exer/linked_list.c'
                sh '/C_ADTs/Lists/List/Exer/main'
            }
        }
    }
}
