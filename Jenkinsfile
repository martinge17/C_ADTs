pipeline {
    agent {
        label 'x86_64_linux' // The label assigned to the Docker agent in Jenkins
    }
    stages {
        stage('Clone'){
            steps{
                sh 'git clone -b test-jenkins https://github.com/martinge17/C_ADTs.git'
            }
        }
        stage('Build Docker Image'){
            steps{
                script{
                    //Build docker image
                    docker.build('cadts-sample')

                }
            }
        }
        stage('Compile Project') {
            steps {
                script {
                    docker.image('cadts-sample').inside {
                        sh 'gcc -o Lists/List/Exer/main Lists/List/Exer/main.c Lists/List/Exer/linked_list.c'
                        sh 'Lists/List/Exer/main'
                    }

                }
            }
        }
                
    }
}
