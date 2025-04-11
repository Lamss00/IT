document.getElementById('sleep-form').addEventListener('submit', function(event) {
    event.preventDefault();

    const sleepHours = document.getElementById('sleep-hours').value;
    const sleepQuality = document.getElementById('sleep-quality').value;

    let feedbackMessage = '';

    if (sleepHours < 7) {
        feedbackMessage += '<p>You should aim for at least 7-8 hours of sleep for optimal health.</p>';
    } else {
        feedbackMessage += '<p>Great job! You are getting enough sleep.</p>';
    }

    if (sleepQuality === 'poor') {
        feedbackMessage += '<p>Consider improving your sleep environment for better quality sleep.</p>';
    } else if (sleepQuality === 'average') {
        feedbackMessage += '<p>Try to maintain a consistent sleep schedule to improve sleep quality.</p>';
    } else {
        feedbackMessage += '<p>Keep up the good work!</p>';
    }

    const feedbackContent = document.getElementById('feedback-content');
    feedbackContent.innerHTML = feedbackMessage;
    feedbackContent.style.display = 'block';
});
