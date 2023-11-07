import express from 'express'

const router = express.Router()

router.get('/curso', getCurso)
router.post('/curso',createCurso)
router.put('/curso/:id', updateCurso)
router.delete('/curso/:id', deleteCurso)

export default router